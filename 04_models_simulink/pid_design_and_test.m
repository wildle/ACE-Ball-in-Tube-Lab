%% pid_design_and_test.m
% Uses model_linearized.m to load sys_tf, then designs and compares PID controllers.

clear; clc;
run("model_linearized.m");

%% -------- PID design (automatic starting point) --------
% Use PID Tuner interactively:
%    pidTuner(sys_tf,'PID')
%
% Or design a baseline PID automatically:
C_pid0 = pidtune(sys_tf,'PID');   % baseline PID
disp("Baseline pidtune PID:");
C_pid0

%% -------- Closed-loop test --------
T0 = feedback(C_pid0*sys_tf, 1);   % closed-loop transfer z/r

figure; step(T0);
grid on; title("Closed-loop step (baseline PID)");

figure; bode(C_pid0*sys_tf);
grid on; title("Open-loop bode (baseline PID)");

%% -------- Optional: try PI or PD too --------
C_pi = pidtune(sys_tf,'PI');
C_pd = pidtune(sys_tf,'PD');

T_pi = feedback(C_pi*sys_tf,1);
T_pd = feedback(C_pd*sys_tf,1);

figure; step(T_pi, T_pd, T0);
grid on; title("Step comparison: PI vs PD vs PID");
legend("PI","PD","PID baseline");
