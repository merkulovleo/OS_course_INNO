#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char static_array[5] = "inno";
    printf ("%s\n", static_array);
    char *dynamic_array = malloc(5 * sizeof(char)); 
    strcpy(dynamic_array, "inno");
    printf("%s\n", dynamic_array);
    dynamic_array = realloc(dynamic_array, 11 * sizeof(char));
    strcpy(dynamic_array, "innopolis");
    printf("%s\n", dynamic_array);
    free(dynamic_array);
    float m[4] = {0.25, 0.5, 0.75, 1};
    float *p = m;
    printf("%zu\n", sizeof(m));
    printf("%zu\n", sizeof(p));
    int n[3][3];
    int value = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            n[i][j] = value++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
    float *q = m;
    float new_array[2][4];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            new_array[i][j] = m[j % 4]; 
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", new_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}

