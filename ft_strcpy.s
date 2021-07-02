global		_ft_strcpy
section		.text

_ft_strcpy:	mov		rcx, -1
loop:		inc 	rcx
			mov		al, byte[rsi + rcx]
			mov		byte[rdi + rcx], al
			cmp		al, 0
			jnz		loop
			mov		rax, rdi
			ret