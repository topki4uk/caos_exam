#  Жесткие и символические ссылки.

### Как создать жесткую ссылку, символическую ссылку, что они представляют из себя с точки зрения файловой системы?

```shell
  # Какой-то файлик
  echo "Hello, links!" > file.txt
```

```shell
  # Создадим хардлинк
  ln file.txt hardlink.txt
```

```shell
  # Создадим симлинк
  ln -s file.txt symlink.txt
```

```shell
  # Что в терминале?
  ls -li
```

### Как работает и какие сисколлы использует программа ln в случае создания жестких ссылок и символических ссылок?

```shell
  # А что по сисколам?
  strace ln file.txt hardlink.txt
```

```text
...
...
...
linkat(AT_FDCWD, "file.txt", AT_FDCWD, "hardlink.txt", 0) = -1 EEXIST (File exists)
openat(AT_FDCWD, "hardlink.txt", O_RDONLY|O_PATH|O_DIRECTORY) = -1 ENOTDIR (Not a directory)
newfstatat(AT_FDCWD, "file.txt", {st_mode=S_IFREG|0664, st_size=14, ...}, AT_SYMLINK_NOFOLLOW) = 0
openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=2996, ...}) = 0
read(3, "# Locale name alias data base.\n#"..., 4096) = 2996
read(3, "", 4096)                       = 0
close(3)                                = 0
...
...
...
```

```shell
  # А для симлинк?
  strace ln -s file.txt symlink.txt
```

```text
...
...
...
symlinkat("file.txt", AT_FDCWD, "symlink.txt") = -1 EEXIST (File exists)
openat(AT_FDCWD, "symlink.txt", O_RDONLY|O_PATH|O_DIRECTORY) = -1 ENOTDIR (Not a directory)
openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=2996, ...}) = 0
read(3, "# Locale name alias data base.\n#"..., 4096) = 2996
read(3, "", 4096)                       = 0
close(3)                                = 0
...
...
...
```