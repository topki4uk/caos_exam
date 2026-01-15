## Что такое разделяемая память?

**IPC (Inter-Process Communication)** — механизмы обмена данными между процессами.

Основные методы:
* Сигналы (асинхронные уведомления)
* Каналы (pipes) и именованные каналы (FIFO)
* Разделяемая память (shared memory) (mmap)
* Очереди сообщений (message queues)
* Семафоры (semaphores)
* Сокеты (sockets) — локальные и сетевые

## Какие сисколлы существуют для создания и управления разделяемой памятью?

```shell
  man 2 shmop
```

## Как посмотреть, какие участки разделяемой памяти существуют в ОС и кто их создал? 

```shell
  ipcs -m -a
```

```text
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 98352      alex       600        3645312    2          dest         
0x00000000 98363      alex       600        2097152    2          dest         
0x00002fbe 98364      alex       666        1000000    2                       

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
```

## Как посмотреть, какие страницы разделяемой памяти сейчас использует данный процесс?

```shell
  pmap -X $(pgrep sharem_write)
```

```shell
  cat /proc/$(pgrep sharem_write)/maps
```

```text
78f19de05000-78f19de12000 rw-p 00000000 00:00 0 
78f19de89000-78f19df7e000 rw-s 00000000 00:01 98364                      /SYSV00002fbe (deleted)
78f19df7e000-78f19df81000 rw-p 00000000 00:00 0 
```