### На какие секции делится адресное пространство процесса?

```shell
  # Посмотрим на мапу памяти
  cat /proc/$(pgrep example)/maps
```

```text
61213797e000-61213797f000 r--p 00000000 08:02 2282183                    /home/alex/CLionProjects/caos_exam/task_18/example  # .text 
61213797f000-612137980000 r-xp 00001000 08:02 2282183                    /home/alex/CLionProjects/caos_exam/task_18/example  #  исполняемые инструкции
612137980000-612137981000 r--p 00002000 08:02 2282183                    /home/alex/CLionProjects/caos_exam/task_18/example  # .ro-data
612137981000-612137982000 r--p 00002000 08:02 2282183                    /home/alex/CLionProjects/caos_exam/task_18/example  # .ro-data
612137982000-612137983000 rw-p 00003000 08:02 2282183                    /home/alex/CLionProjects/caos_exam/task_18/example  # .data + .bss
61214a310000-61214a331000 rw-p 00000000 00:00 0                          [heap]
7239b7200000-7239b7228000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6                 #  Код для либы (конкретно libc)
7239b7228000-7239b73b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7239b73b0000-7239b73ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7239b73ff000-7239b7403000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7239b7403000-7239b7405000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7239b7405000-7239b7412000 rw-p 00000000 00:00 0 
7239b74f4000-7239b74f7000 rw-p 00000000 00:00 0 
7239b7509000-7239b750b000 rw-p 00000000 00:00 0 
7239b750b000-7239b750d000 r--p 00000000 00:00 0                          [vvar]
7239b750d000-7239b750f000 r--p 00000000 00:00 0                          [vvar_vclock]
7239b750f000-7239b7511000 r-xp 00000000 00:00 0                          [vdso]                                             #  Механизм быстрых сисколов
7239b7511000-7239b7512000 r--p 00000000 08:02 1051051                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2     #  Код для динамического линкера
7239b7512000-7239b753d000 r-xp 00001000 08:02 1051051                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7239b753d000-7239b7547000 r--p 0002c000 08:02 1051051                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7239b7547000-7239b7549000 r--p 00036000 08:02 1051051                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7239b7549000-7239b754b000 rw-p 00038000 08:02 1051051                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffeeace8000-7ffeead09000 rw-p 00000000 00:00 0                          [stack]                                            #  Стек
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]                                         #  Устаревший механизм обращения к сисколам
```

### Зачем нужны сисколлы brk и sbrk?

```shell
  man 2 brk
```

```shell
  man 2 sbrk
```

### Как изменился `maps` после `sbrk`?

```text
// Было

5d355fef3000-5d355fef4000 rw-p 00003000 08:02 2282106                    /home/alex/CLionProjects/caos_exam/task_19/mysbrk
5d359591b000-5d359593c000 rw-p 00000000 00:00 0                          [heap]
7143e7e00000-7143e7e28000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// Стало

5d355fef3000-5d355fef4000 rw-p 00003000 08:02 2282106                    /home/alex/CLionProjects/caos_exam/task_19/mysbrk
5d359591b000-5d359593e000 rw-p 00000000 00:00 0                          [heap]
7143e7e00000-7143e7e28000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

### Покажите использование сисколлов mmap и munmap базовом сценарии.

```shell
  man 2 mmap
```

```shell
  man 2 munmap
```

### Немного про права доступа для `mmap`

* `PROT_READ`  - разрешение на чтение
* `PROT_WRITE` - разрешение на запись
* `PROT_EXEC`  - разрешение на исполнение


* `MAP_SHARED`  - изменения будут видны другим процессам и файлам
* `MAP_PRIVATE` - изменения приватны


* `MAP_ANONYMOUS` - **анонимное отображение памяти (мы не привязаны к файлу)**
* `MAP_FIXED` - использует точно указанный адрес, а не выбирает сам

### Как выглядят `maps`?

```shell
  cat /proc/$(pgrep mymmap)/maps
```

```text
// До mmap

61cf14ec9000-61cf14eca000 rw-p 00003000 08:02 2281736                    /home/alex/CLionProjects/caos_exam/task_19/mymmap
61cf3ec11000-61cf3ec32000 rw-p 00000000 00:00 0                          [heap]
745191600000-745191628000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// Сделали mmap

61cf14ec9000-61cf14eca000 rw-p 00003000 08:02 2281736                    /home/alex/CLionProjects/caos_exam/task_19/mymmap
61cf3ec11000-61cf3ec32000 rw-p 00000000 00:00 0                          [heap]
745189600000-745191600000 rw-p 00000000 00:00 0 
745191600000-745191628000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// Очистили память - munmap

61cf14ec9000-61cf14eca000 rw-p 00003000 08:02 2281736                    /home/alex/CLionProjects/caos_exam/task_19/mymmap
61cf3ec11000-61cf3ec32000 rw-p 00000000 00:00 0                          [heap]
745191600000-745191628000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```
