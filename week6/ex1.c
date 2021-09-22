#include <stdio.h>


//FCFS


void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapArray( int *a, int *b, size_t n )
{
    for ( size_t i = 0; i < n; i++ )
    {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

// A function to implement bubble sort
void bubbleSort(int arr[][3], int n){
    int i, j;
    int time=0;
    for (i = 0; i < n-1; i++) {

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                swapArray(arr[j], arr[j + 1], 3);
            }
        }
    }
}

void printArray(int arr[][3], int size){
    int i;
    printf("Process ID:  Arrival Time:  Burst Time:    Completion Time:  Waiting Time:  Turnaround Time:\n");
    double avWT = 0;
    double avTaT =0;
    int ct = 0;
    for (i = 0; i < size; i++) {
        ct += arr[i][1];

        int wt = 0;
        int bt_j = 0;
        for (int j = 0; j < i; ++j) {
            bt_j += arr[j][1];
        }
        wt = arr[0][0] + bt_j - arr[i][0];
        if(wt<0){
            wt =0;
        }
        int tat = arr[i][1] + wt;
        printf("\t\t %d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", arr[i][2], arr[i][0], arr[i][1], ct,  wt, tat);
        avWT+=wt;
        avTaT+=tat;
    }
    printf("Average: \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %f \t\t\t %f", avWT/size, avTaT/size);
    printf("\n");

}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    int processes[n][3];
    for(int i=0; i<n; i++) {
        printf("Process # %d\n", i+1);
        printf("Arrival Time is ");
        scanf("%d", &processes[i][0]);
        printf("Burst Time is ");
        scanf("%d", &processes[i][1]);
        processes[i][2] = i+1;
    }
    bubbleSort(processes, n);
    printArray(processes, n);

    return 0;
}
