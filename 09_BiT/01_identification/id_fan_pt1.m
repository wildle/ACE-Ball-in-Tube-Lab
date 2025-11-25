function out = id_fan_pt1(fig_path, child_idx, doPlot, last_sec)

    if nargin < 2 || isempty(child_idx), child_idx = []; end
    if nargin < 3, doPlot = true; end
    if nargin < 4, last_sec = 60; end

    % Load data
    [t, rpm, child_idx] = load_fig_timeseries(fig_path, child_idx, last_sec, true);
    fprintf("Fan rpm → used child %d\n", child_idx);

    omega = 2*pi*rpm/60;
    Ts = mean(diff(t));
    domega = omega - mean(omega(1:200));

    % Step input 10% Duty → 0.5V
    u = zeros(size(t)); u(t >= t(1)+5) = 0.5;

    data = iddata(domega, u, Ts);
    sys = tfest(data, 1, 0, 'Display','off');
    [~, fit] = compare(data, sys);

    num = sys.Numerator{1}; den = sys.Denominator{1};
    K = num(end)/den(1);
    tau = 1/den(2);

    if doPlot
        figure;
        ysim = lsim(sys,u,t);
        plot(t,domega,'b','LineWidth',1.3); hold on;
        plot(t,ysim,'r--','LineWidth',1.5)
        plot_style(gca, sprintf("Fan dynamics identification (PT1), fit=%.2f%%", fit), ...
                   "t [s]", "\Delta\omega [rad/s]");
        legend("Measured \Delta\omega","PT1 fit");
    end

    fprintf("---------------------------------------------------\n");
    fprintf("Fan PT1 identification results:\n");
    fprintf("K_dyn     = %.4f  [rad/s/V]\n", K);
    fprintf("tau_omega = %.4f  [s]\n", tau);
    fprintf("G_fan(s)  = %.4f / (%.4f s + 1)\n", K, tau)
    fprintf("---------------------------------------------------\n");

    out.K = K; out.tau = tau; out.sys = sys;
end
