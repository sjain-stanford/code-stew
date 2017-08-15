clear all;
close all;
clc;
%The circuit diagram is as shown.
V=input('Enter the value of voltage source in the figure:\n');
R=zeros(1,6);
disp('Enter the six resistors R1,R2,R3,R4,R5,R6:');
for i=1:6
    R(i)=input('');
end
disp('Applying Loop analysis to the given circuit:');
r=[R(1)+R(2)+R(5) -R(2) -R(5);R(2) -R(2)-R(3)-R(4) R(4);R(5) R(4) -R(4)-R(5)-R(6)]
v=[V;0;0]
I=inv(r)*v;
disp('The loop currents are:');
disp('I1=');
disp(I(1));
disp('I2=');
disp(I(2));
disp('I3=');
disp(I(3));
disp('Hence the current through the 2 ohm resistor is:');
disp(I(3)-I(2));