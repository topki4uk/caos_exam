//
// Created by alex on 1/14/26.
//

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>


int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: ./mymv [old_path] [new_path]\n");
    return 1;
  }

  if (rename(argv[1], argv[2]) == -1) {
    printf("rename failed: %s\n", strerror(errno));
    return 1;
  }

  return 0;
}
