global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
    call _ft_strlen         ;len in rax
    add rax, 1              ;add 1 to rax
    push rdi                ; save rdi (the string received)
    mov rdi, rax            ;save the len in the first parameter
    call _malloc            ;return the pointer malloced into rax
    pop r15                 ;get the old rdi into r15
    mov rdi, rax            ;destination = malloced string
    mov rsi, r15            ;source = the string received
    call _ft_strcpy
    ret