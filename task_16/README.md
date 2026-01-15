### Как из терминала посмотреть, какие файловые дескрипторы сейчас открыты у данного процесса и какие файлы им соответствуют?

* Посмотреть в директории `/proc`
  ```shell
  ls -la /proc/<PID>/fd
  ```
  
  ```text
    total 0
    dr-x------ 2 alex alex  3 Jan 14 17:13 .
    dr-xr-xr-x 9 alex alex  0 Jan 14 17:13 ..
    lrwx------ 1 alex alex 64 Jan 14 17:13 0 -> /dev/pts/4
    lrwx------ 1 alex alex 64 Jan 14 17:13 1 -> /dev/pts/4
    lrwx------ 1 alex alex 64 Jan 14 17:13 2 -> /dev/pts/4
  ```

* `lsof` - просмотр из консоли
  ```shell
  lsof -p $(pgrep name-of-program)
  ```
  
  ```text
  COMMAND   PID USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME
  htop    13015 alex  cwd    DIR    8,2     4096 2281971 /home/alex/CLionProjects/caos_exam/task_15
  htop    13015 alex  rtd    DIR    8,2     4096       2 /
  htop    13015 alex  txt    REG    8,2   379216 1061923 /usr/bin/htop
  htop    13015 alex  mem    REG    8,2  5719296 1085832 /usr/lib/locale/locale-archive
  htop    13015 alex  mem    REG    8,2  2125328 1051054 /usr/lib/x86_64-linux-gnu/libc.so.6
  htop    13015 alex  mem    REG    8,2    59920 1060543 /usr/lib/x86_64-linux-gnu/libsensors.so.5.0.0
  htop    13015 alex  mem    REG    8,2    27984 1060410 /usr/lib/x86_64-linux-gnu/libnl-genl-3.so.200.26.0
  htop    13015 alex  mem    REG    8,2   133944 1060409 /usr/lib/x86_64-linux-gnu/libnl-3.so.200.26.0
  htop    13015 alex  mem    REG    8,2   952616 1051057 /usr/lib/x86_64-linux-gnu/libm.so.6
  htop    13015 alex  mem    REG    8,2   208328 1060597 /usr/lib/x86_64-linux-gnu/libtinfo.so.6.4
  htop    13015 alex  mem    REG    8,2   239848 1060388 /usr/lib/x86_64-linux-gnu/libncursesw.so.6.4
  htop    13015 alex  mem    REG    8,2    27028 1051043 /usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache
  htop    13015 alex  mem    REG    8,2   236616 1051051 /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
  htop    13015 alex    0u   CHR  136,4      0t0       7 /dev/pts/4
  htop    13015 alex    1u   CHR  136,4      0t0       7 /dev/pts/4
  htop    13015 alex    2u   CHR  136,4      0t0       7 /dev/pts/4
  ```
