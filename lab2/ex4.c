#include <stdio.h>
#include <ctype.h>

int count(char *str, char ch) {
    int i = 0, 
    cnt = 0;
    ch = tolower(ch); 
    while (str[i] != '\0') {
        if (tolower(str[i]) == ch) { 
            cnt++;
        }
        i++;
    }
    return cnt;
}

void countAll(char *str) {
    int i = 0;
    char ch;
    
    while (str[i] != '\0') {
        ch = str[i];
        if (i == 0 || count(str, ch) == 1) { 
            printf("%c:%d ", tolower(ch), count(str, ch));
        }
        i++;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    countAll(argv[1]);

    return 0;
}
