global memset

memset:
	mov rax, rdi
	mov rcx, 0
	call _loop


_loop:
	cmp rcx, rdx
	je _end
	mov byte [rax], sil
	inc rax
	inc rcx
	call _loop


_end:
	mov rax, rdi
	ret
