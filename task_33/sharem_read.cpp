//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1000000

int main() {
  int shm_id;
  char* shm_ptr;

  shm_id = shmget(12222, SHM_SIZE, 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  shm_ptr = (char*) shmat(shm_id, NULL, 0);
  if (shm_ptr == (char*) -1) {
    perror("shmat");
    return 1;
  }

  printf("Reader: Read from shared memory: %s\n", shm_ptr);

  getchar();

  shmdt(shm_ptr);
  return 0;
}