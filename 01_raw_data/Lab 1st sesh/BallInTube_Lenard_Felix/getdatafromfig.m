clc
open('heightrampfor_a2.fig');

a = get(gca,'Children');  % alle Objekte
obj = a(2);  % <- hier das Objekt mit echten Daten auswählen

xdata = obj.XData;
ydata = obj.YData;

% Filtere die letzten 60 Sekunden
time_limit = max(xdata) - 60;
idx = xdata >= time_limit;
xdata_last60 = xdata(idx);
ydata_last60 = ydata(idx);

% Plot der letzten 60 Sekunden
figure;
plot(xdata_last60, ydata_last60, 'LineWidth', 1.4);
xlabel('Zeit [s]');
ylabel('Höhe [m]');
title('Zeit-Höhen-Verlauf (letzte 60 s)');
grid on;

% Klicke z.B. 2 Punkte zum Messen
[xc, yc] = ginput(2);  
disp([xc, yc]);  % zeigt die gemessenen Punkte
