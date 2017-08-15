clear all;
close all;
clc;
%The circuit diagram is as shown
%To calculate Thevenin Voltage
disp('Enter the value of voltage source S:');
S=input('');
disp('Enter the value of current source I:');
I=input('');
R=zeros(1,3);
disp('Enter the resistances R1,R2,R3:');
for i=1:3
    R(i)=input('');
end
%Let the 5th node be grounded
V5=0;
V2=V5+S;
V3=V2-6*I;
V4=V5-I*R(3);
V1=(V3*(3+1/R(2))+V2/R(1))/(3+1/R(1)+1/R(2));
Vt=V4-V1;
disp('The voltages at the nodes 1,2,3,4,5 are:');
disp(V1);
disp(V2);
disp(V3);
disp(V4);
disp(V5);
disp('The Thevenin voltage is:');
disp(Vt);
%To calculate Thevenin Resistance
%The loop currents are I,i2,i3,i4
r=[-R(1)-R(2) R(1) -6;12 1 1;R(1) -R(1) 2];
v=[6*I;0;-2*I-S];
i=inv(r)*v;
disp('The short circuit current is:');
disp(i(3));
Rt=Vt/i(3);
disp('Hence the Thevenin resistance is:');
disp(abs(Rt));
disp('This Rth remains constant for different values of load resistances.');
%To calculate the power dissipated by 4 ohms
Il(1)=Vt/(abs(Rt)+4);
P=(Il(1)^2*4);
disp('The power dissipated by 4 ohm load (in watts) is:');
disp(P);
%Equivalent Norton circuit
disp('The equivalent Norton circuit has:');
disp('In=');
In=Vt/abs(Rt);
disp(In);
disp('Rn=');
disp(abs(Rt));
