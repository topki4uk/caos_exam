//
// Created by alex on 1/15/26.
//

#include <iostream>
#include <seccomp.h>
#include <unistd.h>

int main() {
  scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ALLOW);

  if (ctx == nullptr) {
    perror("seccomp_init");
    exit(1);
  }

  seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(fork), 0);
  seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(clone), 0);

  if (seccomp_load(ctx) < 0) {
    perror("seccomp_load failed");
    seccomp_release(ctx);
    exit(1);
  }

  printf("Set new rules\n");

  // int pid = fork();
  //
  // if (pid == 0) {
  //   printf("Child process has pid = %d\n", getpid());
  // } else {
  //   printf("Parent process has pid = %d\n", getpid());
  // }

  printf("All is OK!\n");
  return 0;
}