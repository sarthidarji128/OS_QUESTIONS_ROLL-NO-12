//part 1

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGINT, handle_signal);
    while(1) {
        sleep(1);
    }
    return 0;
}

//part 2 

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process\n");
    } else {
        wait(NULL);
        printf("Child has finished execution\n");
    }
    return 0;
}
