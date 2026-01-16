//
// Created by alex on 1/16/26.
//

#include <unistd.h>

int main() {
  const char* path = "/bin/ls";
  const char* argv[] = {"ls", "-l", NULL};
  const char* envp[] = {NULL};

  asm volatile (
    "mov $59, %%rax\n\t"      // номер syscall execve
    "mov %0, %%rdi\n\t"       // path
    "mov %1, %%rsi\n\t"       // argv
    "mov %2, %%rdx\n\t"       // envp
    "syscall"
    :
    : "r"(path), "r"(argv), "r"(envp)
    : "rax", "rdi", "rsi", "rdx", "rcx", "r11"
  );

  return 0;
}