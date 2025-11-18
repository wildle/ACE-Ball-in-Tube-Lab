clc;
close all; 
warning('off', 'all'); 
% Import der Zeitreihendaten
open('rpm.fig'); 
a = get(gca,'Children');  
obj_r = a(2);  
xdata_r_raw = obj_r.XData;
ydata_r_raw = obj_r.YData; % Drehzahl [RPM]
close(gcf);

% --- Cut Data Set (Dynamische Analyse) ---
time_limit = max(xdata_r_raw) - 36.5; 
idx_r = xdata_r_raw >= time_limit;
xdata_cut_r = xdata_r_raw(idx_r);
ydata_cut_r = ydata_r_raw(idx_r);
t_r = xdata_cut_r(:);
Ts_r = mean(diff(t_r));

% --- Definition of the unit step ---
Duty_Cycle = 10; 
Max_Voltage = 5; 
Input_Voltage = (Duty_Cycle / 100) * Max_Voltage; 
u = ones(size(t_r)) * Input_Voltage;
u(1) = 0;

% --- Fokus auf RAD/S ---
y_rpm = ydata_cut_r;              
y_rps = y_rpm / 60;               
y_rads = y_rps * 2 * pi;          

%% 1. Dynamische Analyse (PT1-Modell)
print_tf_tau_form(y_rads, u, Ts_r, 'rad/s', t_r);

%% 2. Stationäre Analyse (Lineare Regression)
% --- Messdaten ---
percent = [0 2 5 8 10 12];      
rpm     = [2950 3300 3650 4050 4250 4500];   

% --- Daten vorbereiten ---
omega = 2*pi*rpm / 60;                   
U = (percent / 100) * 5;           

% --- Lineare Regression: U = a * omega + b ---
p = polyfit(omega, U, 1);
a_reg = p(1);
b_reg = p(2);

% --- Umrechnung auf Modellform: omega = k_omega * (U - u0) ---
% Vergleich: U = (1/k_omega) * omega + u0  ←→ U = a_reg * omega + b_reg
k_omega = 1 / a_reg;      % [rad/s/V] oder [1/s/V]
u0      = b_reg;          % [V]

% --- Ergebnisse anzeigen ---
fprintf('\n\n');
fprintf('---------------------------------------------------\n');
fprintf('  Ergebnisse aus der Linearen Regression (Stationär):\n');
fprintf('  Modellform: omega = k_omega * (U - u0)\n');
fprintf('  k_omega  = %.4f  [rad/s/V]\n', k_omega);
fprintf('  u0       = %.4f  [V]\n', u0);
fprintf('---------------------------------------------------\n');

% --- Plot der Regression ---
omega_fit = linspace(min(omega), max(omega), 200);
U_fit = polyval(p, omega_fit);
figure('Name', 'Lineare Regression: Spannung vs. Winkelgeschwindigkeit');
plot(omega, U, 'o', 'MarkerSize', 8, 'LineWidth', 1.8, 'DisplayName', 'Messdaten'); hold on;
plot(omega_fit, U_fit, '-', 'LineWidth', 1.8, 'DisplayName', 'Lineare Approximation');
xlabel('Winkelgeschwindigkeit \omega [rad/s]');
ylabel('Spannung U [V]');
title('Lineare Approximation zwischen \omega und Spannung');
grid on;
legend('Location', 'best');
hold off;

warning('on', 'all');

%% Functions
function print_tf_tau_form(y_data, u, Ts, unit_label, t_r) 
    
    y_data = y_data(:);
    
    % --- 1. Baseline-Bestimmung und Verschiebung ---
    y_baseline = mean(y_data(1:10)); 
    y_shifted = y_data - y_baseline;
    
    % --- System ID (tfest) ---
    data_obj = iddata(y_shifted, u, Ts); 
    sys_tfest_raw = tfest(data_obj, 1, 0, 'Display', 'off'); 
    
    % --- KONVERTIERUNG ZUR STANDARD PT1 FORM G(s) = K / (Tau*s + 1) ---
    [num, den] = tfdata(sys_tfest_raw, 'v');
    
    A = num(end); 
    a = den(end); 
    
    Tau_tfest = 1 / a;
    K_tfest = A / a;
    
    % --- PLOT: OHNE BASELINE (Start bei 0) ---
    sys_pt1_sim = tf([K_tfest], [Tau_tfest 1]);
    y_sim_shifted = lsim(sys_pt1_sim, u, t_r);
    
    figure('Name', sprintf('Sprungantwort: %s (Ohne Baseline)', upper(unit_label)));
    plot(t_r, y_shifted, 'b-', 'LineWidth', 1.5, 'DisplayName', 'Messdaten (\Delta y)');
    hold on;
    plot(t_r, y_sim_shifted, 'r--', 'LineWidth', 2, 'DisplayName', 'PT1-Modell (\Delta y)');
    plot(t_r, zeros(size(t_r)), 'k:', 'DisplayName', 'Null-Linie'); 
    grid on;
    
    xlabel('Zeit t [s]');
    ylabel(sprintf('\\Delta Drehzahl [%s]', unit_label));
    title(sprintf('Sprungantwort: Messdaten vs. PT1-Modell (%s) - OHNE BASELINE (Start bei 0)', upper(unit_label)));
    legend('Location', 'best');
    hold off;
    
    % --- AUSGABE DER ERGEBNISSE (Dynamisch) ---
    fprintf('---------------------------------------------------\n');
    fprintf('  Übertragungsfunktion G(s) für %s (Dynamisch):\n', upper(unit_label));
    fprintf('  K: %.4f [%s/V] | Tau: %.4f [s]\n', K_tfest, unit_label, Tau_tfest);
    fprintf('  G(s) = %.4f / (%.4f * s + 1)\n', K_tfest, Tau_tfest);
    fprintf('---------------------------------------------------\n');
end