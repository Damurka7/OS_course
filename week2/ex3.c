#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    
    if(argc>1) {
        sscanf(argv[1], "%d", &n);
    }
    int c = n-2;
//printf("%d", n);
    for (int i = 0; i < 2 * n - 1; ++i) {
        if(i%2!=0) {
            for (int j = 0; j < c - i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < i; ++j) {
                printf("*");
            }
            printf("\n");
        }else{
            c++;
        }
    }

    return 0;
}

