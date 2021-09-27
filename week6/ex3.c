#include <stdio.h>
#include "stdlib.h"


//round robin algorithm

int quantum;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapArray(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

int complT = 0;
double avWT = 0;
double avTaT = 0;

void printArray(int **arr, int size) {
    int i;
    //printf("Process ID:  Arrival Time:  Burst Time:    Completion Time:  Waiting Time:  Turnaround Time:\n");

    int ct = 0;
    for (i = 0; i < size; i++) {
        if (arr[i][0] > ct) {
            ct = arr[i][0] + arr[i][1];
        } else {
            ct += arr[i][1] + arr[i][0];
        }


        int wt = 0;
        int bt_j = 0;
        for (int j = 0; j < i; ++j) {
            bt_j += arr[j][1];
        }
        wt = arr[0][0] + bt_j - arr[i][0];

        //wt = complT - arr[i][0];
        if (wt < 0) {
            wt = 0;
        }
        complT = ct;
        int tat = arr[i][1] + wt;
        ct = tat + arr[i][0];
        // printf("\t\t %d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", arr[i][2], arr[i][0], arr[i][1], ct, wt, tat);
        avWT += wt;
        avTaT += tat;
    }
    complT = ct;
//    printf("Average: \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %f \t\t\t %f", avWT / size, avTaT / size);
//    printf("\n");

}

// A function to implement bubble sort
void sortAT(int **arr, int n) {
    int i, j;
    int time = 0;
    for (i = 0; i < n - 1; i++) {

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                swapArray(arr[j], arr[j + 1], 3);
            }
        }
    }

}

void sortBT(int **arr, int n) {
    int i, j;
    int time = 0;
    for (i = 0; i < n - 1; i++) {

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1]) {
                swapArray(arr[j], arr[j + 1], 3);
            }
        }
    }
}

void generalSort(int **arr, int n) {
    sortAT(arr, n);
    int t = 0;

    int key[3] = {0, 0, 0};
    int j = 0;
    for (int i = 1; i < n; ++i) {
        t += arr[i - 1][1];
        key[0] = arr[i][0];
        key[1] = arr[i][1];
        key[2] = arr[i][2];
        j = i - 1;
        while (j >= 0 && arr[j][1] > key[1] && arr[j][0] <= t) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][2] = arr[j][2];
            j = j - 1;
            break;
        }
        arr[j + 1][0] = key[0];
        arr[j + 1][1] = key[1];
        arr[j + 1][2] = key[2];
    }

}

void robinAlg(int **arr, int n, int q) {
    int t = 0;
    printArray(arr, n);
    while (t != complT) {
        for (int i = 0; i < n; ++i) {
            if (!arr[i][5]) {
                if (arr[i][1] > q) {
                    if (arr[i][7] <= 1) {
                        arr[i][4] = (t - arr[i][0]);
                    }else{
                        arr[i][4] = (t - arr[i][0]) - arr[i][7]*q;
                    }
                    arr[i][7] += 1;
                    t += q;
                    arr[i][1] -= 3;
                } else {
                    int wt = 0;
                    wt = t - arr[i][0];
                    t += arr[i][1];
                    arr[i][3] = t;
                    arr[i][5] = 1;
                    if (arr[i][7] <= 1) {
                        arr[i][4] = (t - arr[i][0]);
                    }else{
                        arr[i][4] = (t - arr[i][0]) - arr[i][7]*q;
                    }
                }
            }
        }
    }
    printf("Process ID:  Arrival Time:  Burst Time:    Completion Time:  Waiting Time:  Turnaround Time:\n");
    for (int i = 0; i < n; ++i) {

        printf("\t\t %d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", arr[i][2], arr[i][0], arr[i][6],
               arr[i][3], arr[i][4], arr[i][6] + arr[i][4]);
    }
    printf("Average: \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %f \t\t\t %f", avWT / n, avTaT / n);
    printf("\n");
}


int main() {
    int n;
    printf("quantum = ");
    scanf("%d", &quantum);
    printf("n = ");
    scanf("%d", &n);
    // int processes[n][3];
    int **processes = (int **) malloc(n * sizeof(int *));;
    for (int i = 0; i < n; ++i) {
        processes[i] = (int *) malloc(8 * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        printf("Process # %d\n", i + 1);
        printf("Arrival Time is ");
        scanf("%d", &processes[i][0]);
        printf("Burst Time is ");
        scanf("%d", &processes[i][1]);
        processes[i][2] = i + 1;
        processes[i][3] = 0;// ct
        processes[i][4] = 0;// wt
        processes[i][6] = processes[i][1];// old bt
        processes[i][5] = 0;//1 - process has completed, 0 - process waits
        processes[i][7] = 1;// how many times process was executed
    }
    robinAlg(processes, n, quantum);

    return 0;
}
