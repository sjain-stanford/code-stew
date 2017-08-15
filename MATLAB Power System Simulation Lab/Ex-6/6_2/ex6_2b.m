% Ex-6.2 (Power Electronics)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

V = input('Enter the rms phase voltage: ');
Vm = V*sqrt(2);
alpha=0:0.01:180;
Vo=3*sqrt(3)*Vm/pi*cosd(alpha);
plot(alpha,Vo)
grid on
xlabel('Firing Angle (deg) ------>');
ylabel('Output Voltage (V) ------>');
title('Output voltage vs firing angle');