function out = id_ball_tf(rpm_fig,height_fig,child_idx,doPlot)

    [t_r, rpm, cr] = load_fig_timeseries(rpm_fig, child_idx, 60, true);
    [t_h, h  , ch] = load_fig_timeseries(height_fig,child_idx, 60, true);

    fprintf("Ball rpm   → used child %d\n", cr);
    fprintf("Ball height→ used child %d\n", ch);

    omega = 2*pi*rpm/60;
    Ts = mean(diff(t_r));

    omega_i = interp1(t_r, omega, t_h, "linear","extrap");

    domega = omega_i - mean(omega_i(1:200));
    dh     = h - mean(h(1:200));

    data = iddata(dh,domega,Ts);

    sys = tfest(data, 2, 1, 'Display','off');
    [~, fit] = compare(data, sys);

    if doPlot
        ysim = lsim(sys,domega,t_h);

        figure;
        subplot(2,1,1);
        plot(t_h,domega); plot_style(gca,"Input step (\Delta\omega)","t [s]","\Delta\omega [rad/s]");

        subplot(2,1,2);
        plot(t_h,dh,'b'); hold on;
        plot(t_h,ysim,'r--');
        plot_style(gca,sprintf("Best model fit: %.2f %%",fit),"t [s]","\Delta h [m]");
        legend("Measured \Deltah","Model sim");
    end

    fprintf("---------------------------------------------------\n");
    fprintf("Ball TF identification results:\n");
    fprintf("Best fit = %.2f %%\n", fit);
    disp(sys);
    fprintf("---------------------------------------------------\n");

    out.sys = sys;
end
