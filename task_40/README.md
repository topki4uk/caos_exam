## Как использовать в программе на Си ассемблерную функцию из другого файла?

```shell
  # Потребуется использовать компилятор ассемблерного кода
  sudo apt install nasm
```

```shell
  man nasm
```

#### Компилируем ASM файл

```shell
  # Это команда для NASM, на демо у меня другой скорее всего будет
  nasm -f elf64 is_simple.asm -o is_prime.o
```

```shell
  # Теперь сам C файл
  gcc -c simple_with_asm.c -o simple_with_asm.o
```

```shell
  # Теперь линкуем их вместе
  gcc simple_with_asm.o is_prime.o -o simple_with_asm
```

## Как с помощью gdb делать отладку ассемблерного кода?

```shell
  # Пересоберем asm файл для debug целей
  nasm -f elf64 -g -F dwarf is_simple.asm -o is_prime.o
```

```shell
  # Соберем с дебаг символами
  gcc -g simple_with_asm.o is_prime.o -o debug_simple_with_asm
```

### Какие команды можно использовать в `gdb`?
* `break func_name` - по имени функции
* `layout asm` - графический режим
* `layout reg` - регистры + код

* `print $register` - значение регистра
* `info registers` - все регистры
* `ni` - следующая инструкция (не заходит в `call`)
* `si` - следующая инструкция (заходит в `call`)
* `finish` - выполнить до возврата из функции
