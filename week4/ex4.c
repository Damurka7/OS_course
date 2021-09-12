#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<readline/history.h>

int main() {
    printf("command line - max size of your command is 50 characters\n");
    while (1){
        char in[50];
        printf("->");
        scanf("%[^\n]%*c", in);

        char* new_token[50];
        int i = 0;
        new_token[i] = strtok(in, " ");
        while(new_token[i] != NULL){
            ++i;
            new_token[i] = strtok(NULL, " ");
        }

        pid_t pid = fork();

        if(pid==0){
            execvp(new_token[0], new_token);
        }else{
            wait(NULL);
        }

    }
    return 0;
}
