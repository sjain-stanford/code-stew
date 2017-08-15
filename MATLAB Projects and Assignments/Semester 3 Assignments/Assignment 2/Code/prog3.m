clear all;
close all;
clc;
disp('Please enter the value of AC voltage source:');
V=input('');
disp('Please enter the value of resistance R:');
R=input('');
disp('Please enter the value of inductance L:');
L=input('');
disp('Please enter the value of capacitance C:');
C=input('');
fr=1/(2*pi*sqrt(L*C));
disp('The resonant frequency(in hertz) for the given circuit is:');
disp(fr);
BW=R/(2*pi*L);
disp('The band width BW of the series RLC circuit is:');
disp(BW);
Q=fr/BW;
disp('The Q factor of the series RLC circuit is:');
disp(Q);
syms f
subplot(3,3,1);
fplot(@(f) V*R/sqrt(R^2+(L*2*pi*f-1/(C*2*pi*f))^2),[fr-50 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Voltage across resistor(V)--------->');
title('Vr v\s f');
subplot(3,3,2);
fplot(@(f) V/sqrt(R^2+(L*2*pi*f-1/(C*2*pi*f))^2),[fr-50 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Current(A)--------->');
title('I v\s f');
subplot(3,3,3);
fplot(@(f) sqrt(R^2+(L*2*pi*f-1/(C*2*pi*f))^2),[fr-50 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Impedance(ohm)--------->');
title('Z v\s f');
subplot(3,3,4);
fplot(@(f) L*2*pi*f,[0 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Inductive Reactance(ohm)--------->');
title('XL v\s f');
subplot(3,3,5);
fplot(@(f) 1/(C*2*pi*f),[0 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Capacitive Reactance(ohm)--------->');
title('XC v\s f');
subplot(3,3,6);
fplot(@(f) V*(1/(C*2*pi*f))/sqrt(R^2+(L*2*pi*f-1/(C*2*pi*f))^2),[fr-50 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Voltage across capacitor(V)--------->');
title('Vc v\s f');
subplot(3,3,7);
fplot(@(f) V*(L*2*pi*f)/sqrt(R^2+(L*2*pi*f-1/(C*2*pi*f))^2),[fr-50 fr+50]);
xlabel('Frequency(Hz)-------->');
ylabel('Voltage across inductor(V)--------->');
title('Vl v\s f');
