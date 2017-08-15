; Load PC with 8200 initially
; Store the two numbers to be added in 8240H and 8241H
; using Memory Editor



	.ORG	8200H
SUM	.EQU	01H
CARRY	.EQU	02H
START:	LXI	H,8240H
	MOV	A,M
	INX	H
	ADD	M
	OUT	SUM
	STA	8250H
	JNC	L1
	MVI	A,01H
	OUT	CARRY
	STA	8251H
L1:	HLT
	.END