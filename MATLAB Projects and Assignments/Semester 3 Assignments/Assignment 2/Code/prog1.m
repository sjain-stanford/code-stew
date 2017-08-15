clear all;
close all;
clc;
disp('Enter the value of maximum voltage(Vm):');
Vm=input('');
disp('Enter the phase angle(deg) of V:');
th1=input('');
disp('Enter the value of maximum current(Im):');
Im=input('');
disp('Enter the phase angle(deg) of I:');
th2=input('');
% th1--theta1
% th2--theta2
% ph--phase angle
% pf--power factor
ph=(th2-th1)*pi/180;
pf=cos(ph);
disp('The power factor is:');
disp(pf);
Pavg=(Vm*Im*pf/2);
disp('The average power is:');
disp(Pavg);
Vrms=Vm/sqrt(2);
disp('The rms value of voltage is:');
disp(Vrms);
                                