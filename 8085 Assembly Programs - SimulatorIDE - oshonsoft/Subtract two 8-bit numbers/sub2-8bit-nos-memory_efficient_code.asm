; Program occupies only 0000H - 0012H in the memory
; Does not use LDA, STA (3-byte instructions)
; Uses increment of register pair technique for different addresses (INX, INR are 1-byte instructions)
; For negative numbers, the output is in sign magnitude form: e.g.
; 02H - 09H = 07H (magnitude) with the sign bit set as '1'
; 09H - 02H = 07H (magnitude) with the sign bit set as '0'

	.ORG	0000H
START:	MVI	C,00H		; represent borrow
	LXI	H,0050H
	MOV	A,M
	INX	H
	SUB	M
	INX	H
	JNC	HERE
	CMA			; take 2's complement of
	INR	A		; result if borrow exists
	INR	C
HERE:	MOV	M,A
	INX	H
	MOV	M,C
	HLT
