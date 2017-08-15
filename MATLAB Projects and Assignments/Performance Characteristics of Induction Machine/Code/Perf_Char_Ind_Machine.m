clc
clear all
close all
disp('This is a program that evaluates the performance characteristics of a three-phase induction machine from N.L. and B.R. test results');
fs=input('Enter the supplied frequency:');
P=input('Enter the number of poles created by the stator winding:');
Ns=120*fs/P;
s=-0.2:0.001:0.2;
Nr=Ns*(1.-s);
ws=2*pi*Ns/60;
wr=2*pi.*Nr/60;

%Accepting data from the user:
V=input('Please enter the value of rated line voltage of the machine:\n');
a=menu('How is the stator of the machine connected?','Star','Delta');
if a==1
    Vr=V/sqrt(3);
elseif a==2
    Vr=V;
end

%To get the single phase equivalent circuit parameters from no-load and blocked-rotor test results
Voc=input('Enter the no-load terminal voltage per phase:');
Ioc=input('Enter the no-load current per phase:');
Woc=input('Enter the no-load single phase wattmeter reading:');
Vsc=input('Enter the blocked-rotor terminal voltage per phase:');
Isc=input('Enter the blocked-rotor current per phase:');
Wsc=input('Enter the blocked-rotor single phase wattmeter reading:');
R1=input('Enter the measured stator resistance(a.c.) per phase:');

%No load parameter determination
pfoc=Woc/Voc/Ioc;
Iw=Ioc*pfoc;
Im=Ioc*sqrt(1-pfoc^2);
R0=Voc/Iw;
X0=Voc/Im;
%Blocked rotor parameter determination
Z01=Vsc/Isc;
R01=Wsc/Isc^2;
X01=sqrt(Z01^2-R01^2);
R2dash=R01-R1;

%Calculation
Rldash=R2dash*(1./s-1);
I2dash=Vr./(R01+Rldash+X01*i);
Z0=(R0*X0*i)/(R0+X0*i);
I0=Vr/Z0;
I1=I0+I2dash; %This is the total load current drawn per phase
Pir=3*(abs(I2dash).^2)*R2dash./s; %Three-phase power input to the rotor  %abs returns the magnitude of a complex number
Pd=3*(abs(I2dash).^2).*Rldash; %Total power developed
Td=Pir./ws; %Developed torque
Wm=3*(Woc/3); %Assuming 1/3rd of no-load losses is mechanical losses %Woc is per phase, hence multiplying it by three
Wi=3*(Woc*2/3); %Assuming 2/3rd of no-load losses is iron losses %Woc is per phase, hence multiplying it by three
Wcu1=3*(abs(I1).^2)*R1; %Stator copper losses
Po=Pd-Wm; %Total output power
Pi=Pir+Wcu1+Wi; %Total input power (three phase)
n=Po./Pi*100; %Efficiency
pf=(Pi/3)./(Vr*abs(I1));

%Plots
m=1;
while m~=2
    k=menu('Choose:','Torque-Slip','Power-Slip','Speed-Torque','Slip-Output Power','Load current-Output Power','Speed-Output Power','Efficiency-Output Power','Power Factor-Output Power');
switch k
    case 1
        plot(s*100,Td);
        grid on;
        xlabel('% Slip,s ------>');
        ylabel('Developed Torque,Td (N-m)------>');
        title('Torque-Slip Characteristic');
    case 2
        plot(s*100,Pd);
        grid on;
        xlabel('% Slip,s ------>');
        ylabel('Developed Power,Pd (W) ------>');
        title('Power-Slip Characteristic');
    case 3
        plot(Td,Nr);
        grid on;
        xlabel('Developed Torque,Td (N-m) ------>');
        ylabel('Speed,Nr (RPM) ------>');
        title('Speed-Torque Characteristic');
    case 4
        plot(Po,s*100);
        grid on;
        xlabel('Output Power,Po (W) ------>');
        ylabel('% Slip,s ------>');
        title('Slip-Output Power Characteristic');
    case 5
        plot(Po,sqrt(3)*abs(I1));
        grid on;
        xlabel('Output Power,Po (W) ------>');
        ylabel('Load current,I (A) ------>');
        title('Load Current-Output Power Characteristic');
    case 6
        plot(Po,Nr);
        grid on;
        xlabel('Output Power,Po (W) ------>');
        ylabel('Speed,Nr (RPM) ------>');
        title('Speed-Output Power Characteristic');
    case 7
        plot(Po,n);
        grid on;
        xlabel('Output Power,Po (W) ------>');
        ylabel('% Efficiency,n ------>');
        title('Efficiency-Output Power Characteristic');
    case 8
        plot(Po,pf);
        grid on;
        xlabel('Output Power,Po (W) ------>');
        ylabel('Power Factor,P.F. ------>');
        title('Power Factor-Output Power Characteristic');
end
m=menu('Would you like to plot another characteristic?','Yes','No');
end








