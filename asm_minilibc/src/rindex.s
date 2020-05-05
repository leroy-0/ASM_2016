global rindex

rindex:
	xor 	rax, rax

_nextchar:
    cmp     byte [rdi], 0
    je      _loop
    inc     rdi
    inc 	rax
    jmp     _nextchar

_loop:
	cmp 	byte [rdi], sil
	je 		_found
	cmp 	rax, 0
	je 		_notfound
	dec 	rdi
	dec 	rax
	jmp 	_loop

_notfound:
	mov 	rax, 0
	ret

_found:
	mov 	rax, rdi
	ret