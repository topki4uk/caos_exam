//
// Created by alex on 1/15/26.
//

#include <iostream>
#include <thread>
#include <unistd.h>
#include <signal.h>

void handle_usr1(int sig) {
  std::cout << "Child catch signal\n";
}

void f() {
  signal(SIGUSR1, handle_usr1);

  std::cout << "Child thread. TGID: " << getpid() << ", TID: " << gettid() << '\n';

  while(true) {
    std::cout << "Child working...\n";
    sleep(2);
  }
}

int main() {
  std::thread t(f);

  sleep(1);

  std::cout << "Main thread. TGID: " << getpid() << ", TID: " << gettid() << '\n';
  std::cout << "./thread_sender " << getpid() << ' ' << gettid() + 1 << '\n';

  t.join();

  std::cout << "Main finished\n";
}