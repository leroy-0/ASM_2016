global strcmp

strcmp:
mov al, byte[rdi]
cmp al, 0
je _stop
cmp byte[rsi], 0
je _stop
cmp al, byte[rsi]
jne _stop
inc rdi
inc rsi
jmp strcmp

_stop:
sub al, byte[rsi]
movsx rax, al
ret