clear all;
close all;
clc;
disp('This is a program which pre-determines the voltage regulation of a three phase alternator');
%Accepting data from the user:
V=input('Please enter the value of rated line voltage of the machine:\n');
I=input('Please enter the value of rated line current of the machine:\n');
a=menu('How is the stator of the machine connected?','Star','Delta');
if a==1
    Vr=V/sqrt(3); %Phase voltage
    Ir=I; %Phase current
elseif a==2
    Vr=V; %Phase voltage
    Ir=I/sqrt(3); %Phase current
end
If0=input('Please enter the open-circuit field currents recorded in a row matrix form:\n');
E0=input('Please enter the corresponding values of open circuit line voltages in a row matrix form:\n');
Ifs=input('Enter the field current during short circuit test (including the zero value)\nin a row matrix form:');
Isc=input('Enter the corresponding short circuit line current that is circulated (including the zero value)\nin a row matrix form:');

b=menu('Please select one of these:','Ampere-turn method(M.M.F)','Synchronous impedance method(E.M.F)');

if b==1 %M.M.F. Method
%Getting the best fitting 3rd degree curve by method of least squares:
if a==1
    P0=polyfit(If0,E0/sqrt(3),3);
elseif a==2
    P0=polyfit(If0,E0,3);
end
    
%To plot the O.C.C. and S.C.C.:
a=0:.01:max(If0);
b=polyval(P0,a);
plotyy(a,b,Ifs,Isc); %This function is used to plot both on the same graph, utilizing two different Y-axes.
ylim([0 1.5*Vr]);
xlabel('Field current(A) ------>');
ylabel('Open circuit terminal voltage per phase(V) ------>');
title('O.C.C and S.C.C of a three phase alternator')
grid on;

%Finding out the value of field current at rated terminal voltage(If1):
%To find the root of the above polynomial fit at the rated voltage:
P1=[P0(1) P0(2) P0(3) P0(4)-Vr];
c=roots(P1); %This gives out three roots, out of which we need to select the appropriate one:
i=1;
while E0(i)<=V
    i=i+1;
end
if V==E0(i-1);
    If1=If0(i-1);
else 
    if (If0(i-2)<c(1))&&(If0(i)>c(1))
        If1=c(1);
    elseif (If0(i-2)<c(2))&&(If0(i)>c(2))
        If1=c(2);
    elseif (If0(i-2)<c(3))&&(If0(i)>c(3))
        If1=c(3);
    end
end
disp('Thus the magnitude of field current corresponding to rated phase voltage is:');
disp(If1);
%To find the field current when rated short circuit current flows(If2):
m=(Isc(2))/Ifs(2); %Slope 'm' is found assuming the S.C.C. to be a straight line variation.
If2=I/m; 
disp('The magnitude of field current required to overcome armature reaction effect is:');
disp(If2);

c=1;
while c~=2
    If2=Ir/m;
    k=menu('Select the type of load:','Lag','UPF', 'Lead');
switch(k)
    case 1
       pf=input('Enter the power factor of load:');
       phi=(acosd(pf)); %Returns the cos inverse in degrees
       If2=complex(If2*cosd(90-phi),If2*sind(90-phi));
    case 2
       If2=complex(0,If2);
    case 3
       pf=input('Enter the power factor of load:');
       phi=(acosd(pf)); %Returns the cos inverse in degrees
       If2=complex(-If2*cosd(90-phi),If2*sind(90-phi));
end
If=If1+If2;
mag=sqrt((real(If))^2+(imag(If))^2);
disp('The magnitude of the resultant vector sum of two field currents is:');
disp(mag);
E=polyval(P0,mag);
disp('The corresponding value of generated voltage per phase(E) to overcome all loading effects is:');
disp(E);
VR=(E-Vr)*100/Vr;
disp('Hence the pre-determined voltage regulation is:');
disp(VR);
c=menu('Would you like to pre-determine at a different power factor?','Yes','No');
end

elseif b==2 %E.M.F. Method
R=input('Enter the value of measured stator resistance per phase(a.c.):');
%Getting the best fitting 3rd degree curve by method of least squares:
if a==1
    P0=polyfit(If0,E0/sqrt(3),3);
elseif a==2
    P0=polyfit(If0,E0,3);
end
disp('The rated phase current of the machine is given to be:');
disp(Ir);
%To find the field current when rated short circuit current flows:
m=(Isc(2)/Ifs(2)); %Slope 'm' is found assuming the S.C.C. to be a straight line variation.
If=I/m;
disp('The field current(If) required to circulate rated short-circuit current is:');
disp(If);
%To find the value of open circuit voltage corresponding to the above field current If
E=polyval(P0,If);
disp('The corresponding open-circuit voltage per phase(E) is:');
disp(E);
Zs=E/Ir;
disp('Thus the value of synchronous impedance(Zs) is');
disp(Zs);
Xs=sqrt(Zs^2-R^2);
disp('The value of synchronous reactance(Xs) calculated is:');
disp(Xs);

%To plot the O.C.C. and S.C.C.:
a=0:.01:max(If0);
b=polyval(P0,a);
plotyy(a,b,Ifs,Isc); %This function is used to plot both on the same graph, utilizing two different Y-axes.
ylim([0 1.5*Vr]);
xlabel('Field current(A) ------>');
ylabel('Open circuit terminal voltage per phase(V) ------>');
title('O.C.C and S.C.C of a three phase alternator')
grid on;

c=1;
while c~=2
    k=menu('Select the type of load:','Lag','UPF', 'Lead');
switch(k)
    case 1
       pf=input('Enter the power factor of load:');
       phi=(acosd(pf)); %Returns the cos inverse in degrees
       E1=sqrt((Vr*cosd(phi)+Ir*R)^2+(Vr*sind(phi)+Ir*Xs)^2);
    case 2
       E1=sqrt((Vr+Ir*R)^2+(Ir*Xs)^2);
    case 3
       pf=input('Enter the power factor of load:');
       phi=(acosd(pf)); %Returns the cos inverse in degrees
       E1=sqrt((Vr*cosd(phi)+Ir*R)^2+(Vr*sind(phi)-Ir*Xs)^2);
end
disp('The corresponding value of generated voltage(E) to overcome all loading effects is:');
disp(E1);
VR=(E1-Vr)*100/Vr;
disp('Hence the pre-determined voltage regulation is:');
disp(VR);
c=menu('Would you like to pre-determine at a different power factor?','Yes','No');
end
end
