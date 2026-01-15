# Файловые системы.

### Покажите примеры каждого вида файлов.

Всего существует 7 видов файлов:
* ### Обычный файл
```shell
  ls -l README.md
```
* ### Директория
```shell
  mkdir dirname
  ls -l .
```

* ### FIFO
```shell
  # Создать FIFO
  mkfifo mytube
```

```shell
  # Посмотрим на нее
  ls -l mytube
```

```shell
  # Покричим в трубу
  echo "hello, tube" > mytube
```

```shell
  # Послушаем трубу
  cat < mytube
```

* ### Socket
```shell
  # Создание сокета
  nc -lU mysock.sock
```

```shell
  # Создание сокета
  nc -U mysock.sock
```

```shell
  # Посмотреть тип файла
  ls -l mysock.sock
```

* ### Symlinks

```shell
  # Некоторый текстовик
  echo "some text" > file.txt
```

```shell
  # Создаем симлинк
  ln -s file.txt link.txt
```

```shell
  # Как это показано в терминале
  ls -l file.txt link.txt
```

* ### Devices

  * #### Блочные

    ```shell
      # Блочные девайсы
      ls -l /dev | grep "brw"
    ```
    
  * #### Символьные

    ```shell
      # Символьные девайсы
      ls -l /dev | grep "crw"
    ```

## Что такое inode и как узнать inode для файлов в данной директории?

```shell
  # Посмотреть inode
  ls -li
```

```shell
  # Создать хардлинк
  ln file.txt other.file
```

### Покажите примеры файлов, которым не соответствует никакое дисковое пространство.

```shell
  ls /proc
```