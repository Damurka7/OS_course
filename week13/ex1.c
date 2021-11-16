#include <stdio.h>
int test(int A[], int R[], int n){
    for(int i = 0; i < n; ++i){
        if(A[i] < R[i]){
            return 0;
        }
    }
    return 1;
}
int main() {
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int r, c; // r = 5, c = 3 from the example 
    fscanf(input, "%d%d", &r, &c);
    int E[c], A[c], unmarked[r];
    for (int i = 0; i < c; ++i) {
        fscanf(input, "%d", &E[i]);
    }
    for (int i = 0; i < c; ++i) {
        fscanf(input, "%d", &A[i]);
    }
    int C[r][c], R[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            fscanf(input, "%d", &C[i][j]);
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            fscanf(input, "%d", &R[i][j]);
        }
        unmarked[i] = 1;
    }
    int flag;
    for(int i = 0; i < r; ++i){
        flag = 1;
        for(int j = 0; j < r; ++j){
            if(unmarked[j] == 1 && test(A, R[j], c) == 1){
                flag = 0;
                unmarked[j] = 0;
                for(int k = 0; k < c; ++k){
                    A[k] += C[i][k];
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < r; ++j){
            sum += unmarked[j];
        }
        if(sum == 0){
            break;
        }
        if(flag == 1){
            fprintf(output, "Deadlock detected!\n");
            fprintf(output, "Number of the deadlocked processes: %d\n", sum);
            return 0;
        }
    }
    for(int i = 0; i < c; ++i){
        fprintf(output, "A[%d] = %d ", i, A[i]);
    }
    fprintf(output, "\n");
    fprintf(output, "No deadlock is detected\n");
    fclose(input);
    fclose(output);
    return 0;
}
