#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<readline/history.h>

int main() {
    while (1){
        char in[50];
        printf("->");
        fgets(in, 50, stdin);
        system(in);
    }
    return 0;
}

