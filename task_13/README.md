# Как работает и какие сисколлы использует программа `mv`?

```shell
  strace mv ../file.txt .
```

```text
...
...
...
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7abcad800000
close(3)                                = 0
geteuid()                               = 1000
ioctl(0, TCGETS, {c_iflag=ICRNL|IXON, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
renameat2(AT_FDCWD, "../file.txt", AT_FDCWD, ".", RENAME_NOREPLACE) = -1 EEXIST (File exists)
renameat2(AT_FDCWD, "../file.txt", AT_FDCWD, "file.txt", RENAME_NOREPLACE) = 0
lseek(0, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
close(0)                                = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
```

# Как работает и какие сисколлы использует программа `rm`?

```shell
  strace rm file.txt
```

```text
...
...
...
ioctl(0, TCGETS, {c_iflag=ICRNL|IXON, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
newfstatat(AT_FDCWD, "file.txt", {st_mode=S_IFREG|0664, st_size=0, ...}, AT_SYMLINK_NOFOLLOW) = 0
geteuid()                               = 1000
newfstatat(AT_FDCWD, "file.txt", {st_mode=S_IFREG|0664, st_size=0, ...}, AT_SYMLINK_NOFOLLOW) = 0
faccessat2(AT_FDCWD, "file.txt", W_OK, AT_EACCESS) = 0
unlinkat(AT_FDCWD, "file.txt", 0)       = 0
lseek(0, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
close(0)                                = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
```