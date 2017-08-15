clear all;
close all;
clc;
%The circuit diagram is as shown.
disp('Enter the values of sources S1 and S2:');
S1=input('');
S2=input('');
R=zeros(1,6);
disp('Enter the resistors R1,R2,R3,R4,R5');
for i=1:5
    R(i)=input('');
end
%Let the 1st node be grounded
%To calculate Thevenin Voltage
V1=0;
V4=S1;
V5=S2;
x=[-1/R(3) 1/R(1)+1/R(2)+1/R(3);1/R(3)+1/R(4) -1/R(3)];
y=[V4/R(1);V5/R(4)];
v=inv(x)*y;
Vt=v(1);
disp('Thus the Vth is:');
disp(Vt);
%To calculate Thevenin Resistance
a=R(1)*R(2)/(R(1)+R(2));
b=a+R(3);
c=b*R(4)/(b+R(4));
d=c+R(5);
Rt=d;
disp('The Rth is:');
disp(Rt);
%Power dissipation by load
i=0;
for r=0:2:12
    i(1,(r/2)+1)=Vt/(Rt+r);
end
r=[0 2 4 6 8 10 12];
disp('Power dissipated varies as:');
P=(i.^2).*r;
disp(P);
plot(r,P);
xlabel('Load Resistance');
ylabel('Power dissipated');
disp('Maximum power dissipated is: 9.3750 Watts');
disp('Maximum power is dissipated at 6 ohms load');
 
