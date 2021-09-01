#include <stdio.h>

void figure1(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i+1; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

//version 1 of figure 1: displays n lines
void figure2_v1(int n){
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < i+1; ++j) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n; i > n/2; --i) {
        for (int j = 0; j < i-n/2; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

//version 2 of figure 1: displays n-1 lines if n is even
void figure2_v2(int n){
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < i+1; ++j) {
            printf("*");
        }
        printf("\n");
    }

    if(n%2==0){
        n-=2;
    }
    for (int i = n; i > n/2; --i) {
        for (int j = 0; j < i-n/2; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void figure3(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);

    figure3(n);
    return 0;
}
