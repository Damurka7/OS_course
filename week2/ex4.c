#include <stdio.h>

//I made 2 versions of this method

//just asks to insert two numbers and displays them in reversed order
void swap1(){
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d %d", b, a);
}

//really swaps two variables in memory location
void swap2(int a, int b, int* new_a, int* new_b){
    *new_b = a;
    *new_a = b;
}

int main() {

    swap1();

    int a,b,newa, newb;
    scanf("%d %d", &a, &b);
    swap2(a,b, &newa, &newb);
    printf("%d %d", newa, newb);
    return 0;
}
