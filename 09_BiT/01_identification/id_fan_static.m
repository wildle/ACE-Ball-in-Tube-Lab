function [k_omega, u0] = id_fan_static(percent, rpm, Vmax, doPlot)

    omega = 2*pi*rpm/60;
    U = percent/100 * Vmax;

    p = polyfit(omega, U, 1);
    a = p(1); b = p(2);

    k_omega = 1/a;
    u0 = b;

    if doPlot
        omega_fit = linspace(min(omega), max(omega), 200);
        U_fit = polyval(p, omega_fit);

        figure;
        plot(omega,U,'o','MarkerSize',8); hold on;
        plot(omega_fit,U_fit,'LineWidth',2);
        plot_style(gca,"Fan static fit","\omega [rad/s]","U [V]");
        legend("meas","fit");
    end

    fprintf("Fan static: k_omega=%.4f rad/s/V, u0=%.4f V\n", k_omega,u0);
end
