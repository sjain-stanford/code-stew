; In the memory, store the divisor first, then the dividend
	.ORG	0000H
START:	LXI	H,0050H	; Divisor (2^n)
	MOV	A,M
	MVI	C,00H	; Keeps track of 'n'
; To find out the power (n) to which 2 is raised
	JNC	L1
L3:	CMC
L1:	RAR
	CPI	00H
	JZ	L2
	INR	C
	JC	L3
	JMP	L1
; Now, we know 'n', thus we can find the quotient
L2:	INX	H	; Dividend (even no.)
	MOV	A,M
	JNC	L4
L6:	CMC
L4:	RAR
	DCR C
	JZ	L5
	JC	L6
	JMP	L4
L5:	INX	H	; To store the quotient
	MOV	M,A
	HLT

