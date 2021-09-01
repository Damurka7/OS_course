#include <stdio.h>
#include "limits.h"
#include "float.h"

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("max int is %d , size is %d bytes\n", a, sizeof(a));
    printf("max float is %f , size is %d bytes\n", b, sizeof(b));
    printf("max double is %f , size is %d bytes\n", c, sizeof(c));

    return 0;
}

