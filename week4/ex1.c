#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int n=5;
    if(fork() == 0){
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }else{
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }

    return 0;
}
