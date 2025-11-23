plot(t_sim, u_ref)
xlabel({'$t$\,/\,s'},'Interpreter','latex', 'FontSize', 15)
ylabel({'$U$\,/\,V'},'Interpreter','latex', 'FontSize', 15)
xticks(0:1:12)
yticks(1.2:0.2:2.8)
grid on
set(gca,"TickLabelInterpreter",'latex', 'FontSize', 15)
%%
plot(t_sim, y_ref)
xlabel({'$t$\,/\,s'},'Interpreter','latex', 'FontSize', 15)
ylabel({'$h$\,/\,m'},'Interpreter','latex', 'FontSize', 15)
xticks(0:1:12)
yticks(0:0.05:0.25)
grid on
set(gca,"TickLabelInterpreter",'latex', 'FontSize', 15)

%%
clear all
close all
clc
load('toggling_results.mat');
vs = get(data,"vs");
vs_time = vs.Values.Time;
vs = vs.Values.Data;
uff = get(data,"Uff");
uff_time = uff.Values.Time;
uff = uff.Values.Data;
plot(vs_time, vs)
set(gca,"TickLabelInterpreter",'latex', 'FontSize', 12)
xlabel({'$t$\,/\,s'},'Interpreter','latex', 'FontSize', 12)
ylabel({'$U$\,/\,V'},'Interpreter','latex', 'FontSize', 12)
hold on
plot(uff_time, uff)
hold off
grid on
legend('$vs$', '$u_{ff}$', 'Interpreter','latex')

%%
clear all
close all
clc
load('toggling_results.mat');
y = get(data,"y");
y_time = y.Values.Time;
y = y.Values.Data;
y_ref = get(data,"y_ref");
y_ref_time = y_ref.Values.Time;
y_ref = y_ref.Values.Data;
plot(y_time, y, color=[0.6 0.6 0.6], LineWidth=2)
set(gca,"TickLabelInterpreter",'latex', 'FontSize', 12)
xlabel({'$t$\,/\,s'},'Interpreter','latex', 'FontSize', 12)
ylabel({'$y$\,/\,m'},'Interpreter','latex', 'FontSize', 12)
hold on
plot(y_ref_time, y_ref)
hold off
grid on
legend('$y$', '$y_{ref}$', 'Interpreter','latex')
ylim([0 0.22])

%%
error = get(data,"error");
max(error.Values.Data)