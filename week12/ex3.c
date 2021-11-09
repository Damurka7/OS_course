#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(){
    char* dvc = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int file = open(dvc, O_RDONLY);
    if(file == -1){
        return EXIT_FAILURE;
    }else{
        struct input_event evt;
        int p = 0, e = 0;
        int c = 0, a = 0;
        while(1){
            ssize_t b = read(file, &evt, sizeof(evt));
            if(evt.code == 0 || evt.code == 4 || evt.value == 1) {
                continue;
            }
            if(evt.code == 18){
                e = 1;
                if(p == 1){
                    printf("I passed the Exam!\n");
                    p = 0, e = 0;
                }
            } else if(evt.code == 25){
                p = 1;
                if(c == 1 && a == 1){
                    printf("Get some cappuccino!\n");
                    c = 0, a = 0, p = 0;
                }
                if(e == 1){
                    printf("I passed the Exam!\n");
                    p = 0, e = 0;
                }
            }else if(evt.code == 30){
                a = 1;
                if(c == 1 && p == 1){
                    printf("Get some cappuccino!\n");
                    c = 0, a = 0, p = 0;
                }
            }else if(evt.code == 46){
                c = 1;
                if(p == 1 && a == 1){
                    printf("Get some cappuccino!\n");
                    c = 0, a = 0, p = 0;
                }
            }else{
                p = 0; e = 0;
                c = 0; a = 0;
            }
        }
    }
    fflush(stdout);
    return 0;
}
