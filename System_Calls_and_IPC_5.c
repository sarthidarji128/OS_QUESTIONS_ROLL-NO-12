#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefds[2];
    char buffer[30];
    if (pipe(pipefds) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(pipefds[0]); // Close unused read end
        write(pipefds[1], "Hello from child", 16);
        close(pipefds[1]); // Close write end
    } else if (pid > 0) {
        // Parent process
        close(pipefds[1]); // Close unused write end
        read(pipefds[0], buffer, 30);
        printf("Parent got: %s\n", buffer);
        close(pipefds[0]); // Close read end
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
