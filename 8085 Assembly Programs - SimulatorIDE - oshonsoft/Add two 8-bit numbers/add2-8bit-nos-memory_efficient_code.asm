; Program occupies only 0000H - 0010H in the memory
; Does not use LDA, STA (3-byte instructions)
; Uses increment of register pair technique for different addresses (INX, INR are 1-byte instructions)



	.ORG	0000H
START:	MVI	C,00H		; represent carry
	LXI	H,0050H
	MOV	A,M
	INX	H
	ADD	M
	INX	H
	MOV	M,A
	JNC	HERE
	INR	C
HERE:	INX	H
	MOV	M,C
	HLT
