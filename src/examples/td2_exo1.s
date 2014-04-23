	.text
	.ent main
main:	
	lw $1, 0($0)
	lw $2, 0($1)
	add $6, $5, $4
	add $3, $1, $2
	lw $4, 0($6)
	sub $2, $0, $4
	addi $7, $1, 4
	add $4, $1, $3
	sub $6, $7, $4	
	
	.end main


