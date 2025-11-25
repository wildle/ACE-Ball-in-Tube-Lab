function debug_fig_children(fig_path)
%DEBUG_FIG_CHILDREN  Print and plot all children with X/Y data.

    fig = openfig(fig_path, 'invisible');
    ax  = gca;
    ch  = get(ax, 'Children');

    fprintf("\n=== DEBUG: %s ===\n", fig_path);
    fprintf("Number of children: %d\n", numel(ch));

    for k = 1:numel(ch)
        cls = class(ch(k));
        if isprop(ch(k),'XData') && isprop(ch(k),'YData') ...
                && ~isempty(ch(k).XData) && ~isempty(ch(k).YData)

            xk = ch(k).XData; yk = ch(k).YData;
            fprintf("Child(%d): class=%s | range(y)=%.4g\n", ...
                    k, cls, max(yk)-min(yk));

            figure('Name', sprintf('%s | Child(%d)', fig_path, k));
            plot(xk, yk); grid on;
            title(sprintf('Child(%d) | %s', k, cls));
        else
            fprintf("Child(%d): class=%s (NO XData/YData)\n", k, cls);
        end
    end

    close(fig);
end
