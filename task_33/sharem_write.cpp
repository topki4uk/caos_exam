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

  getchar();

  shm_id = shmget(12222, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  shm_ptr = (char*) shmat(shm_id, NULL, 0);
  if (shm_ptr == (char*) -1) {
    perror("shmat");
    return 1;
  }

  const char* message = "Hello from writer!";
  sprintf(shm_ptr, "%s", message);
  printf("Writer: Wrote to shared memory: %s\n", message);

  getchar();

  shmdt(shm_ptr);
  return 0;
}