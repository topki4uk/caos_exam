//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int sig) {
  printf("Start handling...\n");
  sleep(3);

  sigset_t current_mask;
  sigprocmask(SIG_BLOCK, NULL, &current_mask);

  printf("End handling\n");
}

int main() {
  struct sigaction sa;

  sigset_t mask;
  sigemptyset(&mask);

  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGSEGV);

  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = handler;
  sa.sa_mask = mask;
  sa.sa_flags = 0;

  sigaction(SIGTERM, &sa, NULL);
  pause();

  return 0;
}