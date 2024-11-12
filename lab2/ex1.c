#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MAX;
    unsigned short int usi = USHRT_MAX;
    signed long int sli = LONG_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("%zu %d", sizeof(i), i);
    printf("%zu %d", sizeof(usi), usi);
    printf("%zu %ld", sizeof(sli), sli);
    printf("%zu %f", sizeof(f), f);
    
    return 0;
}
