%% model_linearized.m
% Ball-in-Tube: linearized LTI model around operating point
% This script defines the linearized state-space model and transfer function.
% Fill in the parameters (alpha1, alpha2, alpha3, tau_w, k_w) below.

clear; clc;

%% -------- Parameters (EDIT THESE) --------
alpha1 =  1.86e-12 ;   % [1/(s)]   from your simplified model
alpha2 =  1.36e-6 ;   % [1/m] or equivalent, from your simplified model
alpha3 =  9.81 ;   % [m/s^2]   gravity-related term
tau_w  =  1.7216 ;   % [s]       fan time constant
k_w    =  272.4088 ;   % [1/s/V]   fan gain

u0     =  -1.1812 ;   % [V]       voltage offset (if used later)

%% -------- Operating point --------
% Hovering equilibrium at z_bar (any height in steady state, e.g., 0.15 m):
omega_bar = sqrt(alpha3)/alpha1;      % from (alpha1*omega_bar)^2 = alpha3
u_bar     = u0 + omega_bar/k_w;       % from omega_bar = k_w*(u_bar - u0)

fprintf("Operating point: omega_bar = %.4f rad/s, u_bar = %.4f V\n", omega_bar, u_bar);

%% -------- Linearized state-space matrices --------
a22 = -2*alpha2*sqrt(alpha3);
a23 =  2*alpha1*sqrt(alpha3);
a33 = -1/tau_w;
b3  =  k_w/tau_w;

A = [ 0   1    0 ;
      0  a22  a23;
      0   0   a33];

B = [0; 0; b3];
C = [1 0 0];
D = 0;

sys_ss = ss(A,B,C,D);

%% -------- Transfer function --------
sys_tf = tf(sys_ss);
sys_tf = minreal(sys_tf);

disp("Linearized transfer function G(s) = z/u:");
sys_tf

%% -------- Poles/Zeros (sanity check) --------
disp("Poles of G(s):");
pole(sys_tf)

disp("Zeros of G(s):");
zero(sys_tf)
