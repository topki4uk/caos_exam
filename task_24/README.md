## Что такое приоритет процесса, какой он бывает, как его узнать и как поменять?

### Есть 2 приоритета процесса:
* `Nice value` - статический приоритет, находится в диапазоне (-20 наивысший до 19 наименьший) 
* `Process Priority` - динамический приоритет, диапазон от 0 до 139

### Можно узнать приоритет при помощи следующих команд:

* `ps`
```shell
  # Команда ps для htop
  ps -p $(pgrep htop) -o pid,ni,pri,comm,pcpu,pmem
```

* `top/htop`

```shell
  # htop
  htop
```

* `nice`

```shell
  nice
```

* Из директории `/proc`

```shell
  # Для процесса htop
  cat /proc/$(pgrep htop)/stat
```

### Есть следующие способ задавать приоритеты

* `Nice`
```shell
  # Установим более низкий приоритет
  nice -n 10 ./example
```

```shell
  # Изменим приоритет
  sudo renice -10 $(pgrep example)
```

* `Priority`
```shell
  # Установим более высокий priority
  sudo chrt -f 50 ./example
```

## Что такое CPU affinity данного процесса, как его узнать и как поменять?

**CPU Affinity (маска процессоров)** определяет, на каких ядрах/процессорах может выполняться процесс.
Это битовая маска, где каждый бит соответствует конкретному CPU ядру.

### Как узнать и поменять?

```shell
  # Узнать affinity процесса
  taskset -pc $(pgrep htop)
```

```shell
  # F2 + PROCESSOR
  htop
```

```shell
  # Через /proc 39 значение
  cat /proc/$(pgrep htop)/stat
```

```shell
  # Запустить на конкретных ядрах
  taskset -c 3 ./example
```

```shell
  # Задать для уже работающего процесса
  taskset -cp 0 $(pgrep example)
```

## Что такое process capabilities в Linux, какие они бывают?

**Capabilities** - это механизм в Linux для разделения привилегий суперпользователя (root) на отдельные, более мелкие привилегии. 
Вместо "все или ничего" (быть root или нет), процессы могут иметь только необходимые им привилегии.

```shell
  man 7 capability
```

### Примеры для `capability`

|Capability| Описание                          | Где используется?     |
|----------|-----------------------------------|-----------------------|
|`CAP_CHOWN`| 	Изменять владельца файлов        | `chown`, `chgrp`      |
|`CAP_DAC_OVERRIDE`| 	Обход проверки прав доступа      | Доступ к любым файлам |
|`CAP_KILL`| 	Посылать сигналы любым процессам | `kill`                |


## Как выдать процессу определенные capabilities, как посмотреть имеющиеся?

Приведу примеры для `example`

```shell
  # Просмотр capabilities процесса
  cat /proc/$(pgrep example)/status | grep Cap
```

```shell
  # Установка capabilities
  sudo setcap cap_dac_override+ep ./example
```
