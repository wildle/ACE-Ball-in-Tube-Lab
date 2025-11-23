%% Clean up
clc;
clear all;
close all;

%% Parameters

% given Variables:      % [unit]
A_b     = 13*1e-4;      % [m^2]     ... area ball
m       = 2.7*1e-3;     % [kg]      ... mass of ball
A_t     = 15*1e-4;      % [m^2]     ... area tube
k_l     = 2*1e-5;       % [m^3]     ... drag coefficient
k_v     = 1.27*1e-4;    % [kg/m]    ... air flow coefficient
tau_w   = 1.6;          % [s]       ... fan time constant
k_w     = 28;           % [1/(s*V)] ... fan gain
rho_l   = 1.225;        % [kg/m^3]  ... density of air
g       = 9.81;         % [m/s^2]   ... gravity constant
h_max   = 0.4;          % [m]       ... length of tube
u_max   = 5;            % [V]       ... max fan voltage
A_gap   = A_t-A_b;      % [m^2]     ... air gap

% parameters for symplified mode:
alpha1  = 0.0071;
alpha2  = 0.2237;
alpha3  = g;
tau_w   = 1.7217;
k_w     = 40.7462;

%% Linearized System

% State Space Linearized:
A = [   0                        1                      0;
        0   -2*alpha2*sqrt(alpha3)  2*alpha1*sqrt(alpha3);
        0                        0               -1/tau_w];
b = [0; 0; k_w/tau_w];
c = [1 0 0];
d = 0;

% Transferfunction of Linearized System:
[Num, Den] = ss2tf(A,b,c,d);
G = tf(Num, Den);

% PidTuner for Linearized System:
Kp = 1.5;
Ki = 0.5;
Kd = 1.118;

%% Simulation Parameters

% Limits for Integrator and Initial Cond.:
% Limits for integration [x1, x2, x3]
% [Height of Tube; Velo. of Ball; Rotation Speed of Fan]
UpperLim = [0.35; 100; 200];
LowerLim = [0; -100; 0];
w_0 = sqrt(alpha3)/alpha1;
Init_cond=[0.0; 0; w_0];

%% Polynomial using Prototyping function

% Values for Prototyping function
T = 1.5;              % Transit duration
dT = 1e-3;          % Sample time of the signal
y0 = 0.0;             % Start value
yT = 0.2;           % Final value
t_0T = 0:dT:T;      % Time vector from 0 to T with sample time dT
t_sim = 0:dT:2*T;   % Time vector from 0 to 2*T with sample time dT for simulation
tau = t_0T/T;       % Scaling for the prototype function: tau = t/T

n = order(G);       % Order of my Linerarized System

% Calculate Polynomial using Prototyping function
phi = prototype_fcn(n,T);
phiN = zeros(n+1,length(tau));

for i = 1:n+1
    phiN(i,:) = polyval(phi(i,:),tau);
end

% Calculation of the flat output
% yf ... Flat output in 1st line and its derivatives in the other lines
% Use the previously determined phi4
%b0 = 1;%G.Numerator{1}(end); % Scaling factor is equal to b0 of numerator polynomial
%yf(1,:) = y0/b0+yf(1,:); % add the start value for the non-derived function
yf = (yT-y0)*phiN; % add the scaling factor to the prototype-function
yf(1,:) = y0+yf(1,:); % add the start value for the non-derived function
YF = flipud(yf); % Flip Highest derivative to the 1st row, so that it gets compatible with denominator & numerator polynomial of G!

% Calculation of the input uref and the desired reference trajectory yref
% Formula: u(s) = P(s) * yf(s) / y(s) = Z(s) * yf(s) with G(s) = Z(s)/P(s)
%uref = G.Denominator{1}*YF;
yref = YF(end,:);

z1 = YF(4,:);
z1d = YF(3,:);
z1dd = YF(2,:);
z1ddd = YF(1,:);

omega = (sqrt(z1dd + alpha3)+alpha2*z1d)/(alpha1);
omegad = (0.5*(1./sqrt(z1dd+alpha3)).*z1ddd+alpha2*z1dd)/alpha1;
uref = 1/k_w*(tau_w*omegad + omega);
u_0 = 1/k_w *w_0;


% Scaling the lengths
ur = [uref uref(end)*ones(1,length(t_sim)-length(tau))];
wr = [yref yref(end)*ones(1,length(t_sim)-length(tau))];

% Values for Simulation
simin.time = t_sim';
simin.signals.values = [ur;wr]';