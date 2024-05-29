#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process\n");
        _exit(0);
    } else {
        wait(NULL);
        printf("Parent process\n");
    }
    return 0;
}
