#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 4;
    pid_t pid = fork();
    if (pid < 0) {
        return 1;
    }
    if (pid > 0) {
        printf("Hello from [PID - %d - %d] (Parent)\n", getpid(), n);
        exit(0);
    } else {
        printf("Hello from [PID - %d - %d] (Child)\n", getpid(), n);
        exit(1);
    }
}