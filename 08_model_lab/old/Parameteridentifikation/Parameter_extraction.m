%% Extracting parameters
clear all 
clc

%% PT1 Analysis
% Step Response PT1-Fan
fig_fan_rpm = openfig("FanSpeed.fig");
ax_fan_rpm = fig_fan_rpm.CurrentAxes;
g_array_fan_rpm = ax_fan_rpm.Children;

time_rpm_step = g_array_fan_rpm(2).XData;
fan_rpm_step = g_array_fan_rpm(2).YData;

close(fig_fan_rpm);

% Smoothing the fan speed data using a moving average filter
windowSize = 15; % Define the window size for the moving average
fan_rpm_step_smoothed = movmean(fan_rpm_step, windowSize);

figure
plot(time_rpm_step,fan_rpm_step_smoothed, LineWidth=2)
xlabel('Time/s');
ylabel('Fan Speed/rpm');
title('Step Response of PT1-Fan');
grid on;
hold on
% Calculate the time constant and steady-state value
time_rpm_63 = time_rpm_step(find(fan_rpm_step_smoothed >= max(fan_rpm_step_smoothed)*0.632, 1));
time_rpm_start = 300.8;

tau_w = time_rpm_63 - time_rpm_start;

steadyStateValue = max(fan_rpm_step_smoothed);
starting_value = min(fan_rpm_step_smoothed); 

% Duty cycle 10% to 90%
du = 0.9 - 0.1; % when input dutycycle  
dV = 0.9*5 - 0.1*5; % when input voltage 

dy = 7700-4570;

% Function of PT1 System 
y0   = 4600;          % Startdrehzahl
%dy   = 3100;          % gemessene Änderung
%du   = 0.8;           % Duty-Sprung
k_omega_rpm    = dy/dV;         % 3875 rpm / Duty
k_omega_rps = k_omega_rpm / 60;
tau_omega  = 1.4;           % s (aus 63%-Punkt)
Td   = 1;           % s (Totzeit, grob)

G = tf(k_omega_rpm,[tau_omega 1],'InputDelay',Td);

t = 300:0.01:330;                 % 8 s reichen völlig
u = du*ones(size(t));         % Schritt 0->0.8 Duty
y = lsim(G,u,t);
y_total = y0 + y;

figure
plot(t, y_total, 'k', 'LineWidth', 2);   % Modell
hold on
plot(time_rpm_step, fan_rpm_step_smoothed, 'LineWidth', 2);  % Messung
grid on
xlabel('Time/s')
ylabel('Fan Speed/rpm')
title("Step Response of PT1-Fan: Measurement vs Model")
legend('Model', 'Measurement', 'Location', 'best')
hold off 


%% Helping coefficients a1, a2, a3 

%a3 
a3 = 9.81; % [m/s^2] gravity constant

% a1, extracted by letting the ball hover 

% data ball hovering (dutycycle 8.2)
fig_ball_hover = openfig("BallHover.fig");
ax_ball_hover = fig_ball_hover.CurrentAxes;
g_array_ball_hover= ax_ball_hover.Children;

time_ball_hover = g_array_ball_hover(2).XData;
ball_hover = g_array_ball_hover(2).YData;
close(fig_ball_hover);

omega_bar = mean(ball_hover); %out of fig "BallHover.fig"

a1 = sqrt(a3)/omega_bar;

% a2, out of linear motion of ball 

% data ball height
fig_ball_h = openfig("BallHeight_A2.fig");
ax_ball_h = fig_ball_h.CurrentAxes;
g_array_ball_h = ax_ball_h.Children;

time_ball_h = g_array_ball_h(2).XData;
ball_h = g_array_ball_h(2).YData;
close(fig_ball_h);

% Smoothing the fan speed data using a moving average filter
windowSize = 15; % Define the window size for the moving average
ball_h_smoothed = movmean(ball_h, windowSize);

figure
plot(time_ball_h,ball_h_smoothed, LineWidth=2)
xlabel('Time/s');
ylabel('Ball Height/m');
title('Ball Height linear motion');
grid on;


% data fan speed
t1 = 653; % time window start
t2 = 659; % time window end

idx = (time_ball_h >= t1) & (time_ball_h <= t2);   % range
p   = polyfit(time_ball_h(idx), ball_h(idx), 1);   % h ≈ p1*t + p2
dh  = p(1);                                        % 
b0  = p(2);

% Fit-Gerade zum Visualisieren
t_win  = time_ball_h(idx);
h_fit  = polyval(p, t_win);

hold on
plot(t_win, h_fit, 'k-', 'LineWidth', 2, 'DisplayName','Linearer Fit')
legend('Ball height (smoothed)', 'Linearer Fit','Location','best')




% data fan speed
fig_fan_speed_lin = openfig("Drehzahl_A2.fig");
ax_fan_speed_lin = fig_fan_speed_lin.CurrentAxes;
g_array_fanspeed_lin = ax_fan_speed_lin.Children;

time_fanspeed_lin = g_array_fanspeed_lin(2).XData;
rpm_lin = g_array_fanspeed_lin(2).YData;
close(fig_fan_speed_lin);

% Fenster wie bei der Höhe
t1 = 654; 
t2 = 670;
idx_fs = (time_fanspeed_lin >= t1) & (time_fanspeed_lin <= t2);

omega_lin = mean(rpm_lin(idx_fs));   % rpm

figure
plot(time_fanspeed_lin(idx_fs), rpm_lin(idx_fs), LineWidth=2)
xlabel('Time/s');
ylabel('Fan Speed/m');
title('Fan Speed linear motion');
grid on;

a2 = (a1*(omega_lin - omega_bar)) / dh;

