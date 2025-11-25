function [t, y, child_idx] = load_fig_timeseries(fig_path, child_idx, last_seconds, auto)
    if nargin < 2, child_idx = []; end
    if nargin < 3 || isempty(last_seconds), last_seconds = inf; end
    if nargin < 4, auto = true; end

    fig = openfig(fig_path, 'invisible');
    ax  = findall(fig, 'Type', 'axes');
    ch  = ax.Children;

    % --- Auto-detect: wähle NUR "echte" Linien
    if auto
        realLines = [];
        for k = 1:length(ch)
            if isprop(ch(k), "XData") && isprop(ch(k),"YData") ...
               && length(ch(k).XData) > 1000
                realLines(end+1) = k;
            end
        end

        if isempty(realLines)
            error("No valid data line in %s", fig_path);
        end

        child_idx = realLines(end);   % meist das unterste Objekt
    end

    obj = ch(child_idx);
    t = obj.XData(:);
    y = obj.YData(:);

    % --- Cut last N seconds
    if isfinite(last_seconds)
        tmax = max(t);
        idx = t >= tmax - last_seconds;
        t = t(idx);
        y = y(idx);
    end

    close(fig);
end
