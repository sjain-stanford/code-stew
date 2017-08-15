	.ORG	0000H
START:	LXI	H,0050H
	XRA	A	; Ex-OR A with A --> A is made zero
	MOV	B,M
	INX	H
	MOV	D,M
	MVI	C,00H	; Carry
L1:	ADD	B
	JNC	L2
	INR	C
L2:	DCR	D
	JNZ	L1
	INX	H	; To store result
	MOV	M,A
	INX	H	; To store carry
	MOV	M,C
	HLT
