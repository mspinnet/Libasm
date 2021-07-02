global		_ft_strdup
extern		_ft_strlen
extern		_ft_strcpy
extern		_malloc
extern		___error
section		.text

_ft_strdup:	push	rdi
			call	_ft_strlen
			mov		rdi, rax
			call	_malloc
			cmp		rax, 0
			jz		error
			mov		rdi, rax
			pop		rsi
			call	_ft_strcpy
			ret
error:		push	rax
			call	___error
			pop		rcx
			mov		[rax], rcx
			mov		rax, -1
			ret