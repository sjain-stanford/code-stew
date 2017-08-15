	.ORG	0000H
START:	LXI	H,0050H
	MVI	C,00H	; carry from 16th bit
	MOV	B,M	; higher-order bits of 1st no.
	INX	H
	MOV	A,M	; lower-order bits of 1st no.
	INX	H
	MOV	D,M	; higher-order bits of 2nd no.
	INX	H
	MOV	E,M	; lower-order bits of 2nd no.
	ADD	E
	INX	H	; store the lower-order bits of the result first
	MOV	M,A
	MOV	A,B
	ADC	D
	INX	H	; store the higher-order bits of the result next
	MOV	M,A
	JNC	L1
	INR	C
L1:	INX	H	; finally store the carry
	MOV	M,C
	HLT

