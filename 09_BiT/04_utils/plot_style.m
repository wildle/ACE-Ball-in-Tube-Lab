function plot_style(ax, ttl, xl, yl)
    title(ax, ttl, 'FontSize', 14, 'FontWeight','bold');
    xlabel(ax, xl, 'FontSize', 12);
    ylabel(ax, yl, 'FontSize', 12);
    grid(ax, 'on');
end
