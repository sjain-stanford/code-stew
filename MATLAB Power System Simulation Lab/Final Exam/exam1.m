clc;
clear all;
close all;

x = menu('Choose:','Inductance','Capacitance');
y = menu('Choose:','Symmetrical Spacing','Unsymmetrical Spacing');
if y == 2 && x == 1
    z = menu('Choose:','Transposed','Untransposed');
else
    z = 1;
end

    r = input('Radius of each conductor (in m): ');
    rdash = 0.7788*r;
    if y == 1
        % Symmetrical Spacing
        D = input('Distance between two conductors (in m): ');        
    else
        % Unsymmetrical Spacing
        D12 = input('Distance D12 (in m): ');
        D13 = input('Distance D13 (in m): ');
        D23 = input('Distance D23 (in m): ');
        D = (D12*D13*D23)^(1/3);        
    end
    if x == 1
        % Inductance
        if z == 1
            % Transposed circuit
            L = 2e-7*log(D/rdash);
            Lnew = L*1e6;
            disp('Inductance (mH/km): '); 
            disp(Lnew);
        else
            % Untransposed circuit
            La = 2e-7*abs(log(sqrt(D12*D13)/rdash)-1i*sqrt(3)/2*log(D13/D12))*1e6;
            Lb = 2e-7*abs(log(sqrt(D12*D23)/rdash)-1i*sqrt(3)/2*log(D12/D23))*1e6;
            Lc = 2e-7*abs(log(sqrt(D13*D23)/rdash)-1i*sqrt(3)/2*log(D23/D13))*1e6;
            disp('Inductance in Phase A (mH/km): '); 
            disp(La);
            disp('Inductance in Phase B (mH/km): '); 
            disp(Lb);
            disp('Inductance in Phase C (mH/km): '); 
            disp(Lc);
        end
    else
        % Capacitance
        C = 2*pi*8.854e-12/log(D/r);
        disp('Capacitance (F/m): '); 
        disp(C);
    end
    