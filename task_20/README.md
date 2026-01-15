## Можно ли запросить конкретный виртуальный адрес для выделения памяти?

У `mmap` предусмотрена такая возможность, запустим прогу с флагом `MAP_FIXED`

```shell
  cat /proc/$(pgrep fixed_mmap)/maps
```

```text
// До mmap

63163a300000-63163a301000 r--p 00000000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a301000-63163a302000 r-xp 00001000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a302000-63163a303000 r--p 00002000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a303000-63163a304000 r--p 00002000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a304000-63163a305000 rw-p 00003000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63164a63f000-63164a660000 rw-p 00000000 00:00 0                          [heap]
7193b9000000-7193b9028000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b9028000-7193b91b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b91b0000-7193b91ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b91ff000-7193b9203000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b9203000-7193b9205000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// После mmap

600000000000-600008000000 rw-p 00000000 00:00 0 
63163a300000-63163a301000 r--p 00000000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a301000-63163a302000 r-xp 00001000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a302000-63163a303000 r--p 00002000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a303000-63163a304000 r--p 00002000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63163a304000-63163a305000 rw-p 00003000 08:02 2281683                    /home/alex/CLionProjects/caos_exam/task_20/fixed_mmap
63164a63f000-63164a660000 rw-p 00000000 00:00 0                          [heap]
7193b9000000-7193b9028000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b9028000-7193b91b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b91b0000-7193b91ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b91ff000-7193b9203000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
7193b9203000-7193b9205000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

## Покажите пример использования `mremap`

```shell
  man 2 mremap
```

```shell
  cat /proc/$(pgrep myremap)/maps
```

```text
// До mmap

61fe38ce4000-61fe38ce5000 rw-p 00003000 08:02 2282255                    /home/alex/CLionProjects/caos_exam/task_20/myremap
61fe69206000-61fe69227000 rw-p 00000000 00:00 0                          [heap]
7ebb39a00000-7ebb39a28000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// Первый раз выделили - mmap

61fe38ce4000-61fe38ce5000 rw-p 00003000 08:02 2282255                    /home/alex/CLionProjects/caos_exam/task_20/myremap
61fe69206000-61fe69227000 rw-p 00000000 00:00 0                          [heap]
7ebb31a00000-7ebb39a00000 rw-p 00000000 00:00 0 
7ebb39a00000-7ebb39a28000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

```text
// Второй раз - mremap

61fe38ce4000-61fe38ce5000 rw-p 00003000 08:02 2282255                    /home/alex/CLionProjects/caos_exam/task_20/myremap
61fe69206000-61fe69227000 rw-p 00000000 00:00 0                          [heap]
7ebb25600000-7ebb31a00000 rw-p 00000000 00:00 0 
7ebb39a00000-7ebb39a28000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
```

## Как с помощью `mmap` загрузить файл в оперативную память?

```shell
  cat /proc/$(pgrep file_mmap)/maps
```

```text
// До mmap

5866ead72000-5866ead93000 rw-p 00000000 00:00 0                          [heap]
73a668400000-73a668428000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668428000-73a6685b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685b0000-73a6685ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685ff000-73a668603000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668603000-73a668605000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668605000-73a668612000 rw-p 00000000 00:00 0 
73a668764000-73a668767000 rw-p 00000000 00:00 0 
73a668779000-73a66877b000 rw-p 00000000 00:00 0 
73a66877b000-73a66877d000 r--p 00000000 00:00 0                          [vvar]
73a66877d000-73a66877f000 r--p 00000000 00:00 0                          [vvar_vclock]
73a66877f000-73a668781000 r-xp 00000000 00:00 0                          [vdso]
```

```text
// Загрузили файл - mmap

5866ead72000-5866ead93000 rw-p 00000000 00:00 0                          [heap]
73a668400000-73a668428000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668428000-73a6685b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685b0000-73a6685ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685ff000-73a668603000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668603000-73a668605000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668605000-73a668612000 rw-p 00000000 00:00 0 
73a668764000-73a668767000 rw-p 00000000 00:00 0 
73a668778000-73a668779000 r--p 00000000 08:02 2282691                    /home/alex/CLionProjects/caos_exam/task_20/file.txt
73a668779000-73a66877b000 rw-p 00000000 00:00 0 
73a66877b000-73a66877d000 r--p 00000000 00:00 0                          [vvar]
73a66877d000-73a66877f000 r--p 00000000 00:00 0                          [vvar_vclock]
73a66877f000-73a668781000 r-xp 00000000 00:00 0                          [vdso]
```

```text
// Очистили память - munmap

5866ead72000-5866ead93000 rw-p 00000000 00:00 0                          [heap]
73a668400000-73a668428000 r--p 00000000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668428000-73a6685b0000 r-xp 00028000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685b0000-73a6685ff000 r--p 001b0000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a6685ff000-73a668603000 r--p 001fe000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668603000-73a668605000 rw-p 00202000 08:02 1051054                    /usr/lib/x86_64-linux-gnu/libc.so.6
73a668605000-73a668612000 rw-p 00000000 00:00 0 
73a668764000-73a668767000 rw-p 00000000 00:00 0 
73a668779000-73a66877b000 rw-p 00000000 00:00 0 
73a66877b000-73a66877d000 r--p 00000000 00:00 0                          [vvar]
73a66877d000-73a66877f000 r--p 00000000 00:00 0                          [vvar_vclock]
73a66877f000-73a668781000 r-xp 00000000 00:00 0                          [vdso]
```

## В чем разница между `MAP_SHARED` и `MAP_PRIVATE`?

В контексте задачи про файл: позволяет вносить изменения в сам файл, а не создавать копию текста внутри программы.

## Зачем нужен сисколл `msync`?

```shell
  man 2 msync
```

