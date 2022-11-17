#include <iostream>
#include <unistd.h>
#include <string>
#include <thread>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>

int child_main(void* ptr) {
  std::string s = "biba";
  sethostname(s.data(), s.size());
  system("hostname");
  std::cout << gethostname(s.data(), s.size()) << s.data();
  return 0;
}



int main() {
    size_t stack_size = 1024*10;
    std::unique_ptr<char[]> child_stack(new char[stack_size]);
    pid_t pid = clone(child_main, child_stack.get() + stack_size, CLONE_NEWUTS | CLONE_NEWUSER | SIGCHLD, 0);
    int status = 0;
    wait(&status);
    char hostname[HOST_NAME_MAX];
    std::cout << gethostname(hostname, HOST_NAME_MAX) << hostname;
    return 0;
}
