	.ORG	0000H
START:	LXI	H,0050H	;
	MOV	A,M
	INX	H
	MOV	B,M
	MVI	C,00H	; Carry
	MVI	D,09H	; Counter
	JNC	L1
	CMC
L1:	DCR	D
	JZ	L3
	RAL
	JC	L2
	JMP	L1
L2:	ADD	B
	JNC	L1
	INR	C
	CMC
	JMP	L1
L3:	INX	H
	MOV	M,A
	INX 	H
	MOV	M,C
	HLT