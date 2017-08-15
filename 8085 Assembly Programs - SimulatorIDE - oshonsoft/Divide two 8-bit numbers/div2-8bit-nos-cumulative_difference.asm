	.ORG	0000H
START:	LXI	H,0050H	; Dividend
	MOV	A,M
	INX	H	; Divisor
	MOV	B,M
	MVI	C,00H	; Quotient
L1:	CMP	B
	JC	L2
	SUB	B
	INR	C
	JMP	L1
L2:	INX	H	; To store the quotient
	MOV	M,C
	INX	H
	MOV	M,A	; To store the remainder
	HLT

