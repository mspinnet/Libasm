global		_ft_strcmp
section		.text

_ft_strcmp: mov		rcx, -1
			push	r8
			push	r9
			mov		r8, 0
			mov		r9, 0
loop:		inc 	rcx
			cmp		byte[rdi + rcx], 0
			jz		ifzero
			cmp		byte[rsi + rcx], 0
			jz		res
			jnz		res
ifzero:		cmp		byte[rsi + rcx], 0
			jz		zero
			mov		r8b, byte[rdi + rcx]
			mov		r9b, byte[rsi + rcx]
			sub 	r8, r9
			mov 	rax, r8
			pop 	r8
			pop		r9
			ret
res:		mov		r8b, byte[rdi + rcx]
			mov		r9b, byte[rsi + rcx]
			sub 	r8, r9
			mov 	rax, r8
			cmp 	rax, 0
			jz		loop
			pop 	r8
			pop		r9
			ret
zero:		mov 	rax, 0
			pop 	r8
			pop		r9
			ret