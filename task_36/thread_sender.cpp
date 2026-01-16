//
// Created by alex on 1/16/26.
//

#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <sys/syscall.h>

extern "C" int tgkill(int tgid, int tid, int sig);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Bad args\n");
    return 1;
  }

  int tgid = atoi(argv[1]);
  int tid = atoi(argv[2]);

  printf("Sending SIGUSR1  to thread:\n");
  printf("  TGID: %d\n", tgid);
  printf("  TID:  %d\n", tid);

  int result = syscall(SYS_tgkill, tgid, tid, SIGUSR1);

  if (result == -1) {
    perror("tgkill");
    return 1;
  }

  return 0;
}