clc;
clear all;
close all;

R = 1;
L = 1;
C = 1;

V = 120;

x_init = [V/L 0]';
dT = 1e-3;
data_hist = [];
for t = 0:dT:15
    
    [T integ] = ode45(@rlc,[t t+dT/2 t+dT],x_init);
    x_init = integ(end,:);
    data_hist = vertcat(data_hist,x_init);
    x_init = x_init';
    
end
plot(data_hist(:,2));