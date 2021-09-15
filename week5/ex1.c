#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>



typedef struct {
    pthread_t thread_id;
    int thread_number;
    char* string;

} thread_info;

void *job(void *vargp){
    thread_info *myid = (thread_info *)vargp;
    printf("Thread number: %d, some text\n", myid->thread_number);
}

int main () {
    int n;
    thread_info* tinfo;

    scanf("%d", &n);
    tinfo = calloc(n, sizeof(thread_info));
    for (int i = 0; i < n; ++i) {
        tinfo[i].thread_number = i;
        pthread_create(&tinfo[i].thread_id, NULL, job, (void *)&tinfo[i]);
    }

    exit(EXIT_SUCCESS);

    return 0;
}
