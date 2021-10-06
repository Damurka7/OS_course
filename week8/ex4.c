#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>
#include <sys/resource.h>

// In console I see how much memory it takes, every second it increases by about 10^7 bytes (as required)

int main() {
    char *data;
    int bytes = (1024*1024*10);

    for (int j = 0; j < 10; ++j) {
        data = (char *) malloc(bytes);
        for (int i = 0; i < bytes; ++i) {
            data[i] = '0';
        }
        int who = RUSAGE_SELF;
        struct rusage usage;
        int ret = getrusage(who, &usage);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }



    return 0;
}
