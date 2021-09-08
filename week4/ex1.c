#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int n;
    if(fork() == 0){
        printf("Hello from child [PID - %d]\n", getpid());
    }else{
        printf("Hello from parent [PID - %d]\n", getpid());
    }

    return 0;
}
