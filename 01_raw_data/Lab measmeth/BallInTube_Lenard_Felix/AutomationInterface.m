addpath C:\Users\Administrator\Desktop\BallInTube_Tc3_AI\BallInTube\AutomationInterface_MATLAB_Ball_in_Tube % Automation Interface Class
addpath C:\TwinCAT\3.1\CustomConfig\Modules\Ctrl_only % Directory for Code Generation 

TcSolutionPath = 'C:\Users\Administrator\Desktop\Setup_Ball_in_Tube'; % TC Solution Directory
TcSolutionName = 'Setup_Ball_in_Tube'; % TC Solution Name

% Simulink Directory for generated Code in
% C:\TwinCAT\3.1\CustomConfig\Modules\**Name of the Simulink Controller
% Model**

VsVisible = false; % open VS when true

%% Open Simulink Ctrl_only.slx Model
open Ctrl_only.slx;

%% load Assemblies
Tc3_AI = Tc3AutomationInterface(); % Tc3Automationinterface Constructor

%create VS Instance (visible/invisible)
% VS 2019 is VsVersion 16!
Tc3_AI.CreateNewVisualStudioInstance(16,VsVisible); % change to false for invisible (after Debugging)

%open TwinCAT Solution (Setup_Ball_in_Tube)
Tc3_AI.OpenTwinCatSolution(TcSolutionPath,TcSolutionName,1);
% SysManager available afer .OpenTwinCatSolution

%% Reload TcCom Object 

%Tc3_AI.CreateTcCOM('Ctrl_only')
TcComObject = Tc3_AI.ChangeTcCOM('Ctrl_only'); %Modelname 'Ctrl_only'
% Variablen Verknüpfen

%% activate Solution (Configuration) and Restart TwinCAT in Run Mode

%save Solution
Tc3_AI.ActivateOnDevice('local');

%% halt Script while the Runtime is active, continiou after user input

% global user_confirmed;
% user_confirmed = false;
% 
% disp('If you want to STOP the Controller Enter OK in the Command Line.')
% t = timer('ExecutionMode','fixedRate', 'Period', 0.1, 'TimerFcn',@checkInput);
% start(t);
user_confirmed = false;

while ~user_confirmed
    pause(0.1);
end


disp('TwinCAT wird ausgeschalten...')
% stop(t);
% delete(t);

%% Switch to Config Mode
%Tc3_AI.sysManager.ActivateConfiguration();

%Tc3_AI.SwitchToConfig('local')
Tc3_AI.sysManager.ClearMappingInfo();

Tc3_AI.LinkVariables('TIRT^Task 3^Outputs^Var 2', 'TIID^Device 2 (EtherCAT)^Box 6 (BallInTubeControl)^Outputs^DutyCyclePWM_FAN')
%save Solution
Tc3_AI.SaveSolution();

%% Close Aktive VS Instance
Tc3_AI.closeVsInstance();

%% Callback-Funktion for GUI

% function checkInput(~,~)
% % 
% global user_confirmed
%     if ~user_confirmed
%         user_input = input('','s');
%         if strcmpi(user_input,'ok');
%             user_confirmed = true;
%         else
%             disp('Geben Sie "ok" ein und drücken Sie Enter');
%         end
%     end
%  end
% % 
