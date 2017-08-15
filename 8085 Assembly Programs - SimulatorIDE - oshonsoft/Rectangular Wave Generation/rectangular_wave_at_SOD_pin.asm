START:	.ORG	0000H
	LXI	SP,0090H
	LXI	H,080H	; On-Time = {decimal(HL)}*{no. of T-states in delay loop}*{time period of clock}
	LXI	D,04AH	; Off-Time = {decimal(HL)}*{no. of T-states in delay loop}*{time period of clock}

REPEAT: MVI	A,0D0H
	SIM
	CALL	DELAY
	XCHG
	MVI	A,050H
	SIM
	CALL	DELAY
	XCHG
	JMP	REPEAT
	HLT

DELAY:	MOV	B,H
	MOV	C,L
L1:	DCX	B
	MOV	A,C
	ORA	B
	JNZ	L1
	RET