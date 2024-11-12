#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buffer[1024];

    pipe(pipefd); 
    if (fork() == 0) {
        read(pipefd[0], buffer, sizeof(buffer)); 
        printf("%s", buffer);
    } else {
        fgets(buffer, sizeof(buffer), stdin);
        write(pipefd[1], buffer, sizeof(buffer));
    }
    return 0;
}