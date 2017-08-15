% Ex-1.2 (Circuit Theory)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Ex-1.2 Resonance in a series RLC circuit\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

V=input('Enter the supply voltage (in V): ');
L=input('Enter the value of inductance L (in H): ');
C=input('Enter the value of capacitance C (in F): ');
R=input('Enter the value of resistance R (in ohm): ');

% Resonance occurs when Xl=Xc
fr=1/(2*pi*sqrt(L*C));
disp('Resonant frequency (in Hz): ');
disp(fr);

Xl = L*2*pi*fr;
Xc = 1/(C*2*pi*fr);

I=V/(R+1j*Xl-1j*Xc);
disp('Current (in A): ');
disp(abs(I));

Vr=I*R;
Vl=I*1j*Xl;
Vc=I*-1j*Xc;

disp('V_r (in V): ');
disp(abs(Vr));
disp('V_l (in V): ');
disp(abs(Vl));
disp('V_c (in V): ');
disp(abs(Vc));

Pr=Vr*I*1e-3;
Pl=Vl*I*1e-3;
Pc=Vc*I*1e-3;

disp('Real power dissipated across R (in kW): ');
disp(Pr);
disp('Reactive power across L (in kVAr): ');
disp(Pl);
disp('Reactive power across C (in kVAr): ');
disp(Pc);

for L=60e-3:10e-3:100e-3
    C=(1/(2*pi*fr)^2)/L;
    m=1;
    for f=fr-25:1:fr+25
        Xl = L*2*pi*f;
        Xc = 1/(C*2*pi*f);
        I(m)=V/(R+j*Xl-j*Xc);
        m=m+1;
    end
    f=[fr-25:1:fr+25];
    
    plot(f,I);
    hold on; 
    grid on;
    title('Resonance curve'); 
    xlabel('Frequency (Hz) ----->'); 
    ylabel('Current (A) ----->'); 
    % legend(sprintf('L = %d mH',L*1e3));
end
        
        

