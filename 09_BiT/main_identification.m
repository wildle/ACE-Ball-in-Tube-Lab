clear; close all; clc;
addpath(genpath(pwd));

% Fan dynamic
out_fan_dyn = id_fan_pt1("00_data/fan_step/rpm_fan_step.fig",[],true,60);

% Fan static
out_fan_stat = id_fan_static([0 2 5 8 10 12], ...
                             [2950 3300 3650 4050 4250 4500], 5, true);

% Ball dynamics
out_ball = id_ball_tf("00_data/ball_step/rpm_ball_step.fig", ...
                      "00_data/ball_step/height_ball_step.fig", [], true);

save("02_model/identified_params.mat","out_fan_dyn","out_fan_stat","out_ball");
