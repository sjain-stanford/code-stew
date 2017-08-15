; 0050H should contain lower order byte of 1st no
; 0051H should contain higher order byte of 1st no
; 0052H should contain lower order byte of 2nd no
; 0053H should contain higher order byte of 2nd no
; lower order byte of result is stored in 0054H followed
; by the higher order byte in 0055H
; carry is stored in 0056H



	.ORG	0000H
START:	MVI	A,00H
	LHLD	0050H
	XCHG
	LHLD	0052H
	DAD	D
	SHLD	0054H
	JNC	HERE
	INR	A
HERE:	STA	0056H
	HLT
