#include <stdio.h>

void bblSrt(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void display(int arr[], int n){
    int i;
    for (i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {

    int arr[] = {20, 19, 18, 17, 16, 15, 14};
    int n = sizeof(arr)/sizeof(arr[0]); // automatically calculates the size of the arr 
    display(arr, n);
    bblSrt(arr, n);
    display(arr, n);
    return 0;
}
