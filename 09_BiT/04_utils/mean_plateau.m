function ybar = mean_plateau(t, y, t1, t2)
%MEAN_PLATEAU Mean value of y within [t1, t2].

    idx = (t >= t1) & (t <= t2);
    ybar = mean(y(idx));
end
