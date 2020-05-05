global	strcasecmp

change_char_first_arg:
	add	rcx, 32
	jmp	move_to_scnd

change_char_second_arg:
	add	rdx, 32
	jmp	check_all_arg

do_first_arg:
	cmp	rcx, 'Z'
	jle	change_char_first_arg
	jmp	move_to_scnd

do_second_arg:
	cmp	rdx, 'Z'
	jle	change_char_second_arg
	jmp	check_all_arg

loop:
	movsx	rcx, byte [rdi]
	movsx	rdx, byte [rsi]
	inc	rdi
	inc	rsi
	cmp	rcx, 'A'
	jge	do_first_arg

move_to_scnd:
	cmp	rdx, 'A'
	jge	do_second_arg

_stop:
	mov rax, rcx
	sub rax, rdx
	ret

check_all_arg:
	cmp	rcx, byte 0
	je	_stop
	cmp	rdx, byte 0
	je	_stop
	cmp rcx, rdx
	jne _stop
	je	loop

strcasecmp:
	xor rax, rax
	jmp	loop