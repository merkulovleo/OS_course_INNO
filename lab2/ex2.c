#include <stdio.h>
#include <string.h>

int main() {
    char str[257]; 
    int i = 0;

    while (i < 256) {
        char ch = getchar();
        if (ch == '.' || ch == '\n') {
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i] = '\0'; 

    int len = strlen(str);
    printf("\"");
    for (int j = len - 1; j >= 0; j--) {
        putchar(str[j]);
    }
    printf("\"\n");

    return 0;
}