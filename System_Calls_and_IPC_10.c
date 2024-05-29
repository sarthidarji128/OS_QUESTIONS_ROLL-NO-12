#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    write(1, "SIGINT received\n", 16);
}

int main() {
    signal(SIGINT, sigint_handler);
    while(1) {
        pause();
    }
    return 0;
}
