//
// Created by alex on 1/14/26.
//

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong element of arguments\n";
    return 1;
  }

  DIR* dir = opendir(argv[1]);
  if (dir == nullptr) {
    std::cerr << "opendir failed: " << strerror(errno) << '\n';
    return 1;
  }

  dirent* entry;
  struct stat sb;
  while ((entry = readdir(dir)) != nullptr) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    if (lstat(entry->d_name, &sb) == -1) {
      std::cerr << "( failed: " << strerror(errno) << '\n';
      return 1;
    }

    std::cout << "Name: " << entry->d_name << '\n';
    std::cout << "Inode: " << entry->d_ino << '\n';
    std::cout << "Size: " << sb.st_size << '\n';
    std::cout << "Type: ";

    switch (sb.st_mode & S_IFMT) {
      case S_IFBLK:  printf("block device\n");            break;
      case S_IFCHR:  printf("character device\n");        break;
      case S_IFDIR:  printf("directory\n");               break;
      case S_IFIFO:  printf("FIFO/pipe\n");               break;
      case S_IFLNK:  printf("symlink\n");                 break;
      case S_IFREG:  printf("regular file\n");            break;
      case S_IFSOCK: printf("socket\n");                  break;
      default:       printf("unknown?\n");                break;
    }

    std::cout << '\n';
  }

  closedir(dir);
  return 0;
}