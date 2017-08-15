	.ORG	0000H
START:	LXI	H,0050H
	MVI	C,00H	; borrow to the 16th bit
	MOV	B,M	; higher-order bits of 1st no.
	INX	H
	MOV	A,M	; lower-order bits of 1st no.
	INX	H
	MOV	D,M	; higher-order bits of 2nd no.
	INX	H
	MOV	E,M	; lower-order bits of 2nd no.
	SUB	E
	INX	H	; store the lower-order bits of the result first into memory
	MOV	M,A
	MOV	A,B
	SBB	D
	INX	H	; store the higher-order bits of the result next into memory
	MOV	M,A
	JNC	L1
	INR	C
L1:	INX	H	; finally store the borrow into memory
	MOV	M,C
	HLT

