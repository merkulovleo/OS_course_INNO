#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        return 1;
    }

    if (pid > 0) {
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        sleep(5);
        wait(NULL);
    } else {
        printf("Child PID: %d\n", getpid());
        exit(0);
    }

    return 0;
}