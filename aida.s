.name "aida"
.comment "ZORK MUST DIE"

l2:		sti r1, %:live, %1
		fork %15

live:	live %1
		zjmp %:live
