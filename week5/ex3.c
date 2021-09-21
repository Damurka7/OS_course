#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

FILE *file;

typedef struct {
    pthread_t thread_id;
    int thread_number;
    char* string;

} thread_info;

void *readFromFile(void *vargp){
    thread_info *myid = (thread_info *)vargp;
    printf("Thread number: %d, some text\n", myid->thread_number);

    int thisCharacter;
    char savedString[61];
    file = fopen("file.txt", "r");
    if (file == NULL)
    {
        perror("Error: ");
        return(-1);
    }
    if(fgets(savedString, 60, file) != NULL) {
        // print the return value (aka string read in) to terminal
        printf("%s", savedString);
    }
  // printf("The content of a file is: ", file);
    fclose(file);
}

void *writeToFile(void *vargp){
    file = fopen("file.txt", "w");
    thread_info *myid = (thread_info *)vargp;
    printf("Thread number: %d, some text\n", myid->thread_number);
    fputs("This is testing for fputs...\n", file);
    fclose(file);
}

int main() {
    

    thread_info* tinfo;
    tinfo = calloc(2, sizeof(thread_info));
    pthread_create(&tinfo[0].thread_id, NULL, readFromFile, (void *)&tinfo);
    pthread_create(&tinfo[1].thread_id, NULL, writeToFile, (void *)&tinfo);

    return 0;
}
