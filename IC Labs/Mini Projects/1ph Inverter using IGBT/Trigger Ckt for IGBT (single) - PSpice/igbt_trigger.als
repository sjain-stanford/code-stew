* Schematics Aliases *

.ALIASES
C_C3            C3(1=V_astable 2=$N_0001 )
D_D3            D3(1=$N_0001 2=$N_0002 )
Q_Q1            Q1(c=Vint b=$N_0003 e=$N_0004 )
R_R7            R7(1=$N_0003 2=V_mono )
V_V1            V1(+=$N_0002 -=0 )
C_C4            C4(1=0 2=$N_0005 )
C_C12           C12(1=0 2=$N_0006 )
X_X2            X2(GND=0 TRIGGER=$N_0001 OUTPUT=V_mono RESET=$N_0002
+  CONTROL=$N_0006 THRESHOLD=$N_0007 DISCHARGE=$N_0007 VCC=$N_0002 )
C_C5            C5(1=0 2=$N_0007 )
C_C2            C2(1=0 2=Vc2 )
X_X1            X1(GND=0 TRIGGER=Vc2 OUTPUT=V_astable RESET=$N_0002
+  CONTROL=$N_0005 THRESHOLD=Vc2 DISCHARGE=$N_0008 VCC=$N_0002 )
X_U3            U3(+=0 -=$N_0004 V+=$N_0009 V-=$N_0010 OUT=Vint )
V_V7            V7(+=0 -=$N_0010 )
V_V8            V8(+=$N_0013 -=0 )
V_V9            V9(+=$N_0009 -=0 )
R_R9            R9(1=$N_0014 2=Vint )
R_R4            R4(1=$N_0001 2=$N_0002 )
X_U4            U4(+=$N_0014 -=V_contr V+=$N_0009 V-=$N_0010 OUT=Vcomp )
D_D16           D16(1=Vcomp 2=voutF )
R_R28           R28(1=0 2=voutF )
R_R2            R2(1=Vc2 2=$N_0008 )
R_R12           R12(1=0 2=$N_0017 )
RT_R15           R15(1=$N_0017 t=V_contr )
RB_R15          R15(t=V_contr 2=$N_0013 )
C_C13           C13(1=$N_0004 2=Vint )
R_R10           R10(1=$N_0010 2=$N_0004 )
R_R16           R16(1=$N_0008 2=$N_0002 )
R_R5            R5(1=$N_0007 2=$N_0002 )
_    _(V_astable=V_astable)
_    _(Vint=Vint)
_    _(V_mono=V_mono)
_    _(Vc2=Vc2)
_    _(V_contr=V_contr)
_    _(Vcomp=Vcomp)
_    _(voutF=voutF)
.ENDALIASES
