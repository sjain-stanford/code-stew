% Ex-7.2 (Control Systems)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Program to calculate the time-domain specifications of a 2nd order under-damped system\n\n')
while 1
a = input('Enter the coefficient of s^2 in the closed loop transfer function: ');
b = input('Enter the coefficient of s^1 in the closed loop transfer function: ');
c = input('Enter the coefficient of s^0 in the closed loop transfer function: ');

wn = sqrt(c/a);
del = b/(2*a*wn);
if del<1 && del>0 
    break
end
del
fprintf('This is not an under-damped system. Please re-enter.\n\n')
end
wd = wn*sqrt(1-del^2);
theta = acos(del);

disp('Damping ratio: ');
del
disp('Un-damped natural frequency wn (rad/s): ');
wn
disp('Damped frequency wd (rad/s): ');
wd
disp('Delay time (s): ');
td = (1+0.7*del)/wn
disp('Rise time (s): ');
tr = (pi-theta)/wd
disp('Peak time (s): ');
tp = pi/wd
disp('Peak overshoot (%): ');
Mp = exp(-del*pi/(sqrt(1-del^2)))*100
disp('Settling time for a 2% steady state error (s): ');
ts = 4/(del*wn)
disp('Settling time for a 5% steady state error (s): ');
ts = 3/(del*wn)

t = 0:0.01:ts+1;
out = 1-exp(-del*wn.*t).*sin(wd.*t+theta)/sqrt(1-del^2);
plot(t,out);
grid on;
xlabel('Time(s) ---->');
ylabel('Response ---->');
title('Step response of a 2nd order under-damped system');

