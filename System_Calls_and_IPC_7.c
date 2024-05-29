#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;
    char *str;

    key = ftok("progfile", 65);
    shmid = shmget(key, 1024, 0666|IPC_CREAT);
    str = (char*) shmat(shmid, (void*)0, 0);

    printf("Data read from shared memory: %s\n", str);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
