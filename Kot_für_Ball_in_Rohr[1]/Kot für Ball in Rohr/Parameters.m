%% Ball in Tube 
clear 
clc

%% Parameters 


% Fan Parameters
tau_omega = 1.4;        % [s]
k_omega   = 39.125;     % rpm (%)
a  = 4178.75;                % rpm
u0        = 0;     % [V]

% Helping coefficients for Ball equation
%a1 = sqrt(kL/m) * (kV/AG);
%a2 = sqrt(kL/m) * (AB/AG);%
%a3 = g;

a1 = 7.08e-4;
a2 = 1.11;
a3 = 9.81;

% Working Point
%omega_bar = (AG/kV) * sqrt((m*g)/kL); % = (sqrt(a3)/a1)
omega_bar = sqrt(a3)/a1;
u_bar     = (omega_bar -a) / k_omega + u0;

% Starting values for the working point 
z0 = 0.15;              % [m] frei wählbar
zdot0 = 0;              % [m/s]
omega0 = omega_bar;     % [rad/s] o. RPM – konsistent mit k_omega 


%% Linearized State Space Model 
A = [ 0, 1, 0;
      0, -2*a1*a2*omega_bar,  2*a1^2*omega_bar;
      0, 0, -1/tau_omega ];

B = [0; 0; k_omega/tau_omega];

C = [1 0 0];

D = 0;


state_space_sys = ss(A,B,C,D);

G_lin = tf(state_space_sys)

%% Controller
% Define the PID controller
Kp = 1; % Proportional gain
Ki = 0.1; % Integral gain
Kd = 0.01; % Derivative gain
C_pid = pid(Kp, Ki, Kd);

% Closed-loop system
sys_cl = feedback(C_pid * G_lin, 1);
PID = pidTuner(G_lin,'PID');

% Tuned parameters
Kp_tuned = Tuned_PID.Kp;
Ki_tuned = Tuned_PID.Ki;
Kd_tuned = Tuned_PID.Kd;

%%
u_bp  = [0 10 90 100];          % %
w_tab = [4000 4570 7700 7700];  % rpm
u0    = 0;                     % % Start-Duty hier eintragen
omega0 = interp1(u_bp, w_tab, u0, 'linear');  % Initial condition for w




