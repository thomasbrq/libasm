%define WRITE_SYSCALL   0x2000003

global _ft_read
extern ___error

_ft_read:
    mov     rax, WRITE_SYSCALL
    syscall

    jc      error                            ;if the CF flag (carry flag) is set, jump to error label.

    ret

error:
    mov     r15, rax            ; save errno
    sub     rsp, 8              ; align stack
    call    ___error            ; set errno
    add     rsp, 8              ; retrieve stack
    mov     [rax], r15          ; put errno in return value
    mov     rax, -1
    ret
