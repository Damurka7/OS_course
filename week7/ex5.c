#include <stdio.h>
#include "stdlib.h"
//we did not allocate the "s" in heap
//to avoid segmentation fault we just need to use malloc
int main () {
    char **s = malloc(sizeof(char *));
    char foo [] = " Hello World ";
    *s = foo;
    printf ( "s is %s\n" ,s);
    s[0] = foo ;
    printf ( "s[0] is %s\n" ,s [0]) ;
    return (0) ;
}
