global		_ft_read
extern		___error
section		.text

_ft_read:	mov		rax, 0x2000003
			syscall
			jc		error
			jmp		return
error:		push	rax
			call	___error
			pop		rcx
			mov		[rax], rcx
			mov		rax, -1
return:		ret