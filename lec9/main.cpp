#include <iostream>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main() {
    pid_t pid = getpid();
    std::cout << pid << "\n";

    pid_t pid1 = syscall(SYS_getpid);
    std::cout << pid1 << "\n";


    pid_t pid2 = fork();
    if (pid2 == 0) {
        char* const argv[] = {"expr", "2", "+", "2", "*", "2"};
        execlp(argv[0], argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], NULL);
        exit(0);
    }
    int status = 0;
    wait(&status); 
    return 0;
}
