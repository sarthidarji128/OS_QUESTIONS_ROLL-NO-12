#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok("progfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

    struct sembuf p = { 0, -1, SEM_UNDO };
    struct sembuf v = { 0, 1, SEM_UNDO };

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child trying to get binary semaphore\n");
        semop(semid, &p, 1);
        printf("Child got semaphore\n");
        sleep(2);
        printf("Child releasing semaphore\n");
        semop(semid, &v, 1);
    } else {
        printf("Parent trying to get binary semaphore\n");
        semop(semid, &p, 1);
        printf("Parent got semaphore\n");
        sleep(2);
        printf("Parent releasing semaphore\n");
        semop(semid, &v, 1);
    }
    semctl(semid, 0, IPC_RMID, u);
    return 0;
}
