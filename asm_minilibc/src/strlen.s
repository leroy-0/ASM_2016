global strlen

strlen:
    push    rcx
    xor     rcx, rcx

_nextchar:
    cmp     byte [rdi], byte 0
    jz      _null
    inc     rcx
    inc     rdi
    jmp     _nextchar

_null:
    mov rax, rcx
    pop rcx
    ret