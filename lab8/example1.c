#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *message = malloc(100);
    sprintf(message, "Hello, World!");
    printf("%s\n", message);
    printf("PID: %d\n", getpid()); 
    pause(); 
    return 0;
}