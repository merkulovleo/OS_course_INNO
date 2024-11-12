#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0 || n >= 4) {
        return 1;
    }

    char fifo[256];
    char buffer[1024];

    for (int i = 1; i <= n; i++) {
        snprintf(fifo, sizeof(fifo), "%d", i);
        mkfifo(fifo, 0666);
    }

    for (int i = 1; i <= n; i++) {
        if (fork() == 0) {
            snprintf(fifo, sizeof(fifo), "%d", i);
            int fd = open(fifo, O_WRONLY); 
            while (fgets(buffer, 1024, stdin)) { 
                write(fd, buffer, strlen(buffer)); 
            }
            close(fd);
            return 0;
        }
    }
    
    sleep(2);
    while (wait(NULL) > 0);
    return 0;
}