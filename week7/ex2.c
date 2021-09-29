#include <stdio.h>
#include "stdlib.h"

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    int* arr;
    arr = (int*)malloc(sizeof(int)* n);
    if(arr!=NULL) {
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }

        free(arr);

    }
    
    return 0;
}
