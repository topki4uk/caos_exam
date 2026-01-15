# Права доступа к файлам.

### Как посмотреть, как изменить права доступа?

Можно посмотреть командой `ls`.

```shell
  # Это выглядит так
  ls -l
```

```text
total 80
drwxrwxr-x 14 alex alex 4096 Jan 13 15:54 build
drwxrwxr-x 12 alex alex 4096 Dec  1 00:23 build-asan
drwxrwxr-x 14 alex alex 4096 Dec  1 00:30 cmake-build-debug
-rw-rw-r--  1 alex alex  787 Jan  1 19:42 CMakeLists.txt
drwxrwxr-x  3 alex alex 4096 Jan 12 23:23 cpulimit
drwxrwxr-x  2 alex alex 4096 Nov 10 11:46 docs
drwxrwxr-x  3 alex alex 4096 Nov 30 11:43 du
-rwxrwxr-x  1 alex alex 7426 Nov 30 11:43 llvm.sh
drwxrwxr-x  4 alex alex 4096 Jan  1 19:42 malloc
drwxrwxr-x  3 alex alex 4096 Nov 30 11:43 multiplication
drwxrwxr-x  3 alex alex 4096 Jan  1 19:40 patchelf
-rw-rw-r--  1 alex alex  407 Nov 10 11:46 README.md
-rwxrwxr-x  1 alex alex 9955 Nov 10 11:46 run-clang-format.py
-rwxrwxr-x  1 alex alex  381 Nov 10 11:46 run_linter.sh
drwxrwxr-x  3 alex alex 4096 Jan  1 16:40 strip
drwxrwxr-x  3 alex alex 4096 Nov 10 11:46 tools
drwxrwxr-x  3 alex alex 4096 Jan  1 19:40 top
```

### Почему r и x - это разные права?

Покажу пример для команды `ls`

```shell
  # Создадим новую папку и присвоим ей "правильные" права
  mkdir rootdir
  sudo chown root:root rootdir
  sudo chmod 711 rootdir # Доступ на исполнение, но не чтение
```

Как результат: __зайти__ в папку можно, но __читать__ нельзя.

### Как поменять владельца файла, как поменять группу владельца?

```shell
  sudo chown root file.txt
```

```shell
  sudo chgrp root file.txt
```

### Какие сисколлы используются для всего вышеперечисленного?

```shell
  sudo strace chown root file.txt
```

```text
...
...
...
newfstatat(AT_FDCWD, "/etc/nsswitch.conf", {st_mode=S_IFREG|0644, st_size=594, ...}, 0) = 0
newfstatat(AT_FDCWD, "/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/etc/nsswitch.conf", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=594, ...}) = 0
read(3, "# /etc/nsswitch.conf\n#\n# Example"..., 4096) = 594
read(3, "", 4096)                       = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=594, ...}) = 0
close(3)                                = 0
openat(AT_FDCWD, "/etc/passwd", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=2970, ...}) = 0
lseek(3, 0, SEEK_SET)                   = 0
read(3, "root:x:0:0:root:/root:/bin/bash\n"..., 4096) = 2970
close(3)                                = 0
newfstatat(AT_FDCWD, "file.txt", {st_mode=S_IFREG|0664, st_size=13, ...}, AT_SYMLINK_NOFOLLOW) = 0
fchownat(AT_FDCWD, "file.txt", 0, -1, 0) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
```

### Что такое sticky bit?

```shell
  # Создадим директорию
  mkdir somedir
  echo "hello sticky bit" > somedir/file.txt
```

```shell
  # Выдадим стики бит
  sudo chmod 1777 somedir
```

### Что такое suid-бит, что означают права доступа s и S у файла?

```shell
  # Создадим файлик с правами только для рута
  echo "secret info" > secret.txt
  sudo chown root:root secret.txt && sudo chmod 770 secret.txt 
```

```shell
  # Дадим read_secret права на запуск от имени суперпользователя
  sudo chown root read_secret && sudo chmod u+s read_secret
```

Для `SGID` все работает аналогично.

### Покажите примеры файлов, которые ими обладают. 

* `/usr/bin/su`

### Что такое атрибуты файлов, какие они бывают, как посмотреть и как поменять атрибуты файлов?

```shell
  # Посмотреть аттрибуты
  man lsattr
```

```shell
  # Задать аттрибуты
  man chattr
```

```shell
  # Запретим изменение и удаление файла 
  sudo chattr +i file.txt
```
