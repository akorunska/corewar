.name    "se
bc" 
.comment "sebc"

st	r1, :l2
	ld	%4, r3
l1:	live	%1
l3:	ldi	%:l2, r2, r001
l2: add	r2, r3, r2
live:	xor	r4, r4, r4
	zjmp	%:l3
