# Что такое манглирование и как (в общих чертах) оно работает? 

```text
# readelf -s example

Symbol table '.symtab' contains 42 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS Scrt1.o
     2: 000000000000038c    32 OBJECT  LOCAL  DEFAULT    4 __abi_tag
     3: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
     4: 00000000000010b0     0 FUNC    LOCAL  DEFAULT   16 deregister_tm_clones
     5: 00000000000010e0     0 FUNC    LOCAL  DEFAULT   16 register_tm_clones
     6: 0000000000001120     0 FUNC    LOCAL  DEFAULT   16 __do_global_dtors_aux
     7: 0000000000004150     1 OBJECT  LOCAL  DEFAULT   26 completed.0
     8: 0000000000003da8     0 OBJECT  LOCAL  DEFAULT   22 __do_global_dtor[...]
     9: 0000000000001160     0 FUNC    LOCAL  DEFAULT   16 frame_dummy
    10: 0000000000003da0     0 OBJECT  LOCAL  DEFAULT   21 __frame_dummy_in[...]
    11: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS example.cpp
    12: 0000000000002013     1 OBJECT  LOCAL  DEFAULT   18 _ZNSt8__detail30[...]
    13: 0000000000002014     1 OBJECT  LOCAL  DEFAULT   18 _ZNSt8__detail30[...]
    14: 0000000000002015     1 OBJECT  LOCAL  DEFAULT   18 _ZNSt8__detail30[...]
    15: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    16: 00000000000020f4     0 OBJECT  LOCAL  DEFAULT   20 __FRAME_END__
    17: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS 
    18: 0000000000002018     0 NOTYPE  LOCAL  DEFAULT   19 __GNU_EH_FRAME_HDR
    19: 0000000000003db0     0 OBJECT  LOCAL  DEFAULT   23 _DYNAMIC
    20: 0000000000003fb0     0 OBJECT  LOCAL  DEFAULT   24 _GLOBAL_OFFSET_TABLE_
    21: 0000000000004010     0 NOTYPE  GLOBAL DEFAULT   25 _edata
    22: 0000000000004000     0 NOTYPE  WEAK   DEFAULT   25 data_start
    23: 0000000000002000     4 OBJECT  GLOBAL DEFAULT   18 _IO_stdin_used
    24: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@G[...]
    25: 0000000000001169    43 FUNC    GLOBAL DEFAULT   16 main
    26: 0000000000004008     0 OBJECT  GLOBAL HIDDEN    25 __dso_handle
    27: 0000000000001194     0 FUNC    GLOBAL HIDDEN    17 _fini
    28: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_mai[...]
    29: 0000000000001080    38 FUNC    GLOBAL DEFAULT   16 _start
    30: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZStlsISt11char_[...]
    31: 0000000000001000     0 FUNC    GLOBAL HIDDEN    12 _init
    32: 0000000000004010     0 OBJECT  GLOBAL HIDDEN    25 __TMC_END__
    33: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND exit@GLIBC_2.2.5
    34: 0000000000004040   272 OBJECT  GLOBAL DEFAULT   26 _ZSt4cout@GLIBCXX_3.4
    35: 0000000000004000     0 NOTYPE  GLOBAL DEFAULT   25 __data_start
    36: 0000000000004158     0 NOTYPE  GLOBAL DEFAULT   26 _end
    37: 0000000000004040     0 NOTYPE  GLOBAL DEFAULT   26 __bss_start
    38: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _ZSt21ios_base_l[...]
    39: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterT[...]
    40: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    41: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMC[...]
```

## Как по манглированному имени восстановить исходное?

```shell
  # Деманглирует имена
  c++filt _ZSt4cout
```

```shell
  # Деманглирует имена
  nm -C example
```

## Как посмотреть список символов в данном ELF-файле? 

```shell
  # Вывести символы через nm
  nm example
```

```shell
  # Вывести символы через readelf
  readelf -s example
```

## Что делает команда strip?

Удаляет лишние секции и символы из ELF файла, например, debug инфу, что уменьшает вес файла.

```shell
  # Компилим пример
  g++ -g example.cpp -o example
```

```shell
  # Вырезаем лишнее
  strip -s example -o stripped_example
```

```shell
  # Фиксируем прибыль
  ls -lh example stripped_example
```