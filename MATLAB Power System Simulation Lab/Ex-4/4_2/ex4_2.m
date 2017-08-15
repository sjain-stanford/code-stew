% Ex-4.2 (Transmission System)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Ex-4.2 Inductance of a single-phase transmission line\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

c = menu('Choose:','Solid conductors','Bundled conductors');
if c==1    
    D = input('Enter the distance (in metre) between the two solid conductors of a phase: ');
    r1 = input('Enter the radius of conductor 1: ');
    r2 = input('Enter the radius of conductor 2: ');
    
    GMR1 = 0.7788*r1;
    GMR2 = 0.7788*r2;
    L = 2e-7*log(D/GMR1) + 2e-7*log(D/GMR2);
    Lnew = L*1e6;
    disp('Loop Inductance (mH/km): '); Lnew    
end

if c==2
    d = menu('Choose:','2 sub-conductors','3 sub-conductors','General case');
    switch d
        case 1
            fprintf('**** Enter specifics (in metre) of phase A sub-conductors ****\n');
            r1 = input('Radius r1: ');
            r2 = input('Radius r2: ');
            D12 = input('Distance D12: ');
            fprintf('**** Enter specifics (in metre) of phase B sub-conductors ****\n');           
            ra = input('Radius ra: ');
            rb = input('Radius rb: ');
            Dab = input('Distance Dab: ');
            fprintf('**** Enter mutual distances (in metre) ****\n'); 
            D1a = input('M1a: ');
            D1b = input('M1b: ');
            D2a = input('M2a: ');
            D2b = input('M2b: ');
            
            % Calculations
            D11 = 0.7788*r1;
            D22 = 0.7788*r2;
            Daa = 0.7788*ra;
            Dbb = 0.7788*rb;
            
            MGMD = (D1a*D1b*D2a*D2b)^(1/4);
            SGMDa = (D11*D12*D12*D22)^(1/4);
            SGMDb = (Daa*Dab*Dab*Dbb)^(1/4);
            
            L = 2e-7*log(MGMD/SGMDa) + 2e-7*log(MGMD/SGMDb);
            Lnew = L*1e6;
            disp('Loop Inductance (mH/km): '); Lnew            
        
        case 2
            fprintf('**** Enter specifics (in metre) of phase A sub-conductors ****\n');
            r1 = input('Radius r1: ');
            r2 = input('Radius r2: ');
            r3 = input('Radius r3: ');
            D12 = input('Distance D12: ');
            D23 = input('Distance D23: ');
            D13 = input('Distance D13: ');
            fprintf('**** Enter specifics (in metre) of phase B sub-conductors ****\n');           
            ra = input('Radius ra: ');
            rb = input('Radius rb: ');
            rc = input('Radius rc: ');
            Dab = input('Distance Dab: ');
            Dbc = input('Distance Dbc: ');
            Dac = input('Distance Dac: ');
            fprintf('**** Enter mutual distances (in metre) ****\n'); 
            D1a = input('M1a: ');
            D1b = input('M1b: ');
            D1c = input('M1c: ');
            D2a = input('M2a: ');
            D2b = input('M2b: ');
            D2c = input('M2c: ');
            D3a = input('M3a: ');
            D3b = input('M3b: ');
            D3c = input('M3c: ');
            
            % Calculations
            D11 = 0.7788*r1;
            D22 = 0.7788*r2;
            D33 = 0.7788*r3;
            Daa = 0.7788*ra;
            Dbb = 0.7788*rb;
            Dcc = 0.7788*rc;
            
            MGMD = (D1a*D1b*D1c*D2a*D2b*D2c*D3a*D3b*D3c)^(1/9);
            SGMDa = (D11*D12*D13*D12*D22*D23*D13*D23*D33)^(1/9);
            SGMDb = (Daa*Dab*Dac*Dab*Dbb*Dbc*Dac*Dbc*Dcc)^(1/9);
            
            L = 2e-7*log(MGMD/SGMDa) + 2e-7*log(MGMD/SGMDb);
            Lnew = L*1e6;
            disp('Loop Inductance (mH/km): '); Lnew  
            
        case 3
            m = input('Enter the no of sub-conductors in phase A: ');
            n = input('Enter the no of sub-conductors in phase B: ');
            fprintf('**** Enter specifics (in metre) of phase A sub-conductors ****\n');
            for k = 1:1:m
                Da(k,k) = input(sprintf('Radius r%d: ',k))*0.7788;
            end
            for k = 1:1:m
                for l = k+1:1:m                    
                    Da(k,l) = input(sprintf('Phase A --> Distance --> D%d%d: ',k,l));
                    Da(l,k) = Da(k,l);
                end
            end
            fprintf('**** Enter specifics (in metre) of phase B sub-conductors ****\n');
            for k = 1:1:n
                Db(k,k) = input(sprintf('Radius r%d: ',k))*0.7788;
            end
            for k = 1:1:n
                for l = k+1:1:n
                    Db(k,l) = input(sprintf('Phase B --> Distance --> D%d%d: ',k,l));
                    Db(l,k) = Db(k,l);
                end
            end
            fprintf('**** Enter mutual distances (in metre) ****\n'); 
            for k = 1:1:m
                for l = 1:1:n
                M(k,l) = input(sprintf('Mutual: M%d%d: ',k,l));
                end
            end
            
            MGMD = 1;
            for k = 1:1:m
                for l = 1:1:n
                MGMD = MGMD*M(k,l);
                end
            end
            MGMD = MGMD^(1/(m*n));
            
            SGMDa = 1;
            for k = 1:1:m
                for l = 1:1:m
                SGMDa = SGMDa*Da(k,l);
                end
            end
            SGMDa = SGMDa^(1/(m^2));
            
            SGMDb = 1;
            for k = 1:1:n
                for l = 1:1:n
                SGMDb = SGMDb*Db(k,l);
                end
            end
            SGMDb = SGMDb^(1/(n^2));
            
            L = 2e-7*log(MGMD/SGMDa) + 2e-7*log(MGMD/SGMDb);
            Lnew = L*1e6;
            disp('Loop Inductance (mH/km): '); Lnew            
       
    end  
    
end