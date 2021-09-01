#include <stdio.h>
#include "string.h"
#include "limits.h"

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    gets(str);

    int len = strlen(str);

    char reversed[len];

    for (int i = 0; i<len; i++){
        reversed[i] = str[len-i-1];
    }
    printf("%s\n",reversed);

    return 0;
}

