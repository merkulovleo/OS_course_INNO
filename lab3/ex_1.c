#include <stdio.h>
#include <stdlib.h>

const int tri(int * const p, int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    p[0] = 0; 
    p[1] = 1; 
    p[2] = 1; 


    int temp;
    for (int i = 3; i < n; ++i) {  
        temp = p[0] + p[1] + p[2];
        
        p[0] = p[1];
        p[1] = p[2];
        p[2] = temp;
    }

    return p[2];
}

int main() {
    int x = 1; 
    int p[3]; 
    int n = 10;

    p[0] = x;
    p[1] = x;
    p[2] = 2 * x;

    printf("%d %d\n", n, tri(p, n));
    printf("%p\n", (void*)&p[0]);
    printf("%p\n", (void*)&p[1]);
    printf("%p\n", (void*)&p[2]);

    return 0;
}