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
    } else {
        struct input_event evt;
        while(1){
            if(evt.code > 512){
                size_t b = read(file, &evt, sizeof(evt));
                continue;
            }
            if(evt.code != 0 && evt.code != 4 && evt.value == 0)
                printf("PRESSED 0x00%x (%d)\n", evt.code, evt.code);
            ssize_t b = read(file, &evt, sizeof(evt));
            if(evt.code != 0 && evt.code != 4 && evt.value == 0)
                printf("RELEASED 0x00%x (%d)\n", evt.code, evt.code);
        }
    }
    fflush(stdout);
    return EXIT_SUCCESS;
}
