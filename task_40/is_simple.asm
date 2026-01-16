section .note.GNU-stack noalloc noexec nowrite progbits
section .text
global is_simple

is_simple:
        push    rbp
        mov     rbp, rsp
        mov     DWORD [rbp-20], edi
        cmp     DWORD [rbp-20], 1
        jg      .L2
        mov     eax, 1
        jmp     .L3
.L2:
        mov     DWORD [rbp-4], 2
        jmp     .L4
.L6:
        mov     eax, DWORD [rbp-20]
        cdq
        idiv    DWORD [rbp-4]
        mov     eax, edx
        test    eax, eax
        jne     .L5
        mov     eax, 1
        jmp     .L3
.L5:
        add     DWORD [rbp-4], 1
.L4:
        mov     eax, DWORD [rbp-4]
        cmp     eax, DWORD [rbp-20]
        jl      .L6
        mov     eax, 0
.L3:
        pop     rbp
        ret