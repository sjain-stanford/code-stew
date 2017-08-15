% Ex-1.1 (Parallel RLC circuit)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Ex-1.1 Parallel RLC Circuit\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

ch = 1;

while ch~=2
    
fprintf('Enter the supply voltage\n');
v1 = input('magnitude (volt): ');
v2 = input('phase angle (degree): ');
R = input('Enter the resistance (R): ');
Xl = input('Enter the inductive reactance (Xl): ');
Xc = input('Enter the capacitive reactance (Xc): ');
f = input('Enter the supply frequency (Hz): ');


% theta in degrees
t = 0:0.0001:30e-3;
theta = 2*pi*f.*t;

% Complex quantities
v = complex(v1*cosd(v2),v1*sind(v2));
ir = v/R;
il = v/(1i*Xl);
ic = v/(-1i*Xc);
is = ir+il+ic;
pr = v*ir;
pl = v*il;
pc = v*ic;

% Calculations
V = abs(v)*sqrt(2)*sin(theta+angle(v));
IR = abs(ir)*sqrt(2)*sin(theta+angle(ir));
IL = abs(il)*sqrt(2)*sin(theta+angle(il));
IC = abs(ic)*sqrt(2)*sin(theta+angle(ic));
IS = abs(is)*sqrt(2)*sin(theta+angle(is));

Pr = V.*IR;
Pl = V.*IL;
Pc = V.*IC;
Ps = V.*IS;

pf = cos(angle(v)-angle(is))

% Plots

subplot(2,2,1);

grid on;
hold on;
plot(t,V);
plot(t,IR,'r');
plot(t,IL,'g');
plot(t,IC,'m');
xlabel('time (s) ------>');
ylabel('voltage (V), current (A) ------>');
title('Source Voltage and Current drawn by R, L and C v/s time');
legend('Vs','Ir','Il','Ic');              

subplot(2,2,2);

plot(t,IS);
grid on;
xlabel('time (s) ------>');
ylabel('current (A) ------>');
title('Instantaneous Source Current v/s time');
legend('Is');

subplot(2,2,3);

grid on;
hold on;
plot(t,Pr,'r');
plot(t,Pl,'g');
plot(t,Pc,'b');
xlabel('time (s) ------>');
ylabel('power (W) ------>');
title('Power in R, L and C v/s time');
legend('Pr','Pl','Pc');

subplot(2,2,4);

plot(t,Ps);
grid on;
xlabel('time (s) ------>');
ylabel('power (W) ------>');
title('Instantaneous Supply Power v/s time');
legend('Ps');

ch = menu('Would you like to run it all over again?','Yes','No');

clc
clear all;
close all;

end