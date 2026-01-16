## Инструкции безусловного и условного перехода в ассемблере.

#### Безусловный переход

 * `jmp` - инструкция безусловного перехода
```asm
jmp label   ; перейти на заметку label
jmp reg     ; Перейти по адресу в регистре
```

#### Условные переходы

* Переходы по результату сравнения чисел
  * Для беззнаковых: 
    ```asm
    ja  label     ; Jump if Above (a > b)
    jae label     ; Jump if Above or Equal (a >= b)
    jb  label     ; Jump if Below (a < b)  
    jbe label     ; Jump if Below or Equal (a <= b)
    ```
    
    ```asm
    cmp eax, ebx   ; Сравниваем EAX и EBX как беззнаковые
    ja greater     ; Если EAX > EBX (беззнаковое)
    ```

  * Для знаковых
    ```asm
    jg  label     ; Jump if Greater (a > b)
    jge label     ; Jump if Greater or Equal (a >= b)
    jl  label     ; Jump if Less (a < b)
    jle label     ; Jump if Less or Equal (a <= b)
    ```
    
    ```asm
    cmp eax, ebx   ; Сравниваем EAX и EBX как знаковые
    jl less        ; Если EAX < EBX (знаковое)
    ```
    
  * Переходы по флагам
    ```asm
    je  label     ; Jump if Equal (ZF=1)
    jne label     ; Jump if Not Equal (ZF=0)
        
    jz  label     ; Jump if Zero (ZF=1) - синоним je
    jnz label     ; Jump if Not Zero (ZF=0) - синоним jne
    ```
    
    ```asm
    test eax, eax   ; Устанавливает ZF если EAX=0
    jz zero         ; Если EAX == 0
    ```

## Регистр флагов.

#### EFLAGS/RFLAGS (Flags Register)
* `CF` (Carry): перенос/заём
* `ZF` (Zero) - результат ноль
* `PF` (Parity) - чётность
* `SF` (Sign) - знак (отрицательный)
* `IF` (Interrupt) - разрешение прерываний

## Какие есть условные переходы и как (идейно) они работают?

* #### Описано выше

## Как написать аналоги `if`, `while` и `for` на ассемблере?

* Для `if-else` конструкции
    ```c++
    // Код самой конструкции
    
    void compare(int a) {
        if(a > 10) {
            a += 5;
        } else if (a > 5) {
            a += 3;
        } else {
            a = 5;
        }
    }
    ```
  
    ```asm
    ; Уже скомпилированный пример

    compare(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        cmp     DWORD PTR [rbp-4], 10
        jle     .L2
        add     DWORD PTR [rbp-4], 5
        jmp     .L5
    .L2:
        cmp     DWORD PTR [rbp-4], 5
        jle     .L4
        add     DWORD PTR [rbp-4], 3
        jmp     .L5
    .L4:
        mov     DWORD PTR [rbp-4], 5
    .L5:
        nop
        pop     rbp
        ret
    ```
  
* Для `while`
    ```c++
    void cycle() {
        int i = 0;
        while (i < 10) {
            i++;
        }
    }
    ```
  
    ```asm
    cycle():
            push    rbp
            mov     rbp, rsp
            mov     DWORD PTR [rbp-4], 0
            jmp     .L2
    .L3:
            add     DWORD PTR [rbp-4], 1
    .L2:
            cmp     DWORD PTR [rbp-4], 9
            jle     .L3
            nop
            nop
            pop     rbp
            ret
    ```

* Для `for` конструкции

    ```c++
    void cycle() {
        int counter = 0;
    
        for (int i = 0; i < 10; ++i) {
            counter++;
        }
    }
    ```
  
    ```asm
    cycle():
            push    rbp
            mov     rbp, rsp
            mov     DWORD PTR [rbp-4], 0
            mov     DWORD PTR [rbp-8], 0
            jmp     .L2
    .L3:
            add     DWORD PTR [rbp-4], 1
            add     DWORD PTR [rbp-8], 1
    .L2:
            cmp     DWORD PTR [rbp-8], 9
            jle     .L3
            nop
            nop
            pop     rbp
            ret
    ```