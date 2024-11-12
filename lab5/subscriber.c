#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <subscriber_id>\n", argv[0]);
        return 1;
    }

    char fifo[256];
    snprintf(fifo, sizeof(fifo), "/tmp/ex1/s%s", argv[1]);

    int fd = open(fifo, O_RDONLY);
    char buffer[1024];

    while (read(fd, buffer, 1024) > 0) {
        printf("%s", buffer);
    }

    close(fd);
    return 0;
}