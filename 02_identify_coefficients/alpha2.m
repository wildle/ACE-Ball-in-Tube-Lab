% known constants
m = 2.7e-3;       % kg
AB = 12.57e-4;    % m^2
AT = 14.52e-4;    % m^2
AGAP = AT - AB;
kL = 6.5e-5;      % kg/m
kV = 8.8e-6;      % m^3
g = 9.81;         % m/s^2

alpha1 = sqrt(kL/m) * kV;
alpha2 = sqrt(kL/m) * AB / AGAP;
alpha3 = g;

z_dot = gradient(z)./Ts;           % dz/dt
z_ddot = gradient(z_dot)./Ts;      % d2z/dt2
z_ddot_model = (alpha1*omega - alpha2*z_dot).^2 - alpha3;

figure;
plot(t, z_ddot, 'b', t, z_ddot_model, 'r--');
legend('Measured', 'Model');
xlabel('Time [s]');
ylabel('Ball acceleration [m/s^2]');
grid on;
