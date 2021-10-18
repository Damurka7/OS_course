#include <stdio.h>
#include "stdlib.h"

struct page {
    int number;
    int counter;
    int last_cycle_used;
};

int is_full (struct page page_frame[], int n){
    int c =0;
    for (int i = 0; i < n; ++i) {
        if (page_frame[i].number == -1){
            c++;
        }
    }
    if (c==0){
        return 1;
    }else{
        return 0;
    }
}

int main () {
    int  n, m;
    scanf("%d %d" , &n, &m);
    int in[m][2];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &in[i][0], &in[i][1]);
    }

    struct page page_frame[n];
    for (int i = 0; i < n; ++i) {
        page_frame[i].number = -1;
        page_frame[i].counter = -1;
        page_frame[i].last_cycle_used = -1;
    }

    //adding first element to the page frame
    page_frame[0].number = in[0][1];
    page_frame[0].last_cycle_used = in[0][0];
    page_frame[0].counter = 0;
    printf("%d\n", 0);


    int counter = 0;

    for (int i = 1; i < m; ++i) {
        int b = 0;
        if(in[i-1][0] == in[i][0]){//if we are in current cycle
            if(is_full(page_frame, n) == 1){//if page frame is full, then search an element with the smallest counter and page number

                int c = 0;//but before we should check if page is already in page frame
                int memory = -1;
                for (int j = 0; j < n; ++j) {
                    if(page_frame[j].number == in[i][1]){
                        c++;
                        memory = j;
                    }
                }

                if(c==0) {//if there is no such page
                    b = 0;
                    int min = page_frame[0].counter;
                    int d = 0;//shows which page is needed to be evicted
                    for (int j = 0; j < n; ++j) {
                        if (page_frame[j].counter < min) {
                            min = page_frame[j].counter;//found min counter
                        }
                    }
                    int min_number = 999999;
                    for (int j = 0; j < n; ++j) {//searching for page with min number in case if we have several pages with the same min counter
                        if (page_frame[j].counter == min && page_frame[j].number < min_number) {
                            min_number = page_frame[j].number;
                            d = j;
                        }
                    }
                    //we have found the page to evict
                    page_frame[d].number = in[i][1];
                    page_frame[d].counter = 0;
                    page_frame[d].last_cycle_used = in[i][0];
                }else{//if there is such page
                    b = 1;
                    page_frame[memory].last_cycle_used = in[i][0];
                }
            }else{//case if page frame is not full

                int c = 0;//but before we should check if page is already in page frame
                int memory = -1;
                for (int j = 0; j < n; ++j) {
                    if(page_frame[j].number == in[i][1]){
                        c++;
                        memory = j;
                    }
                }

                if(c==0) {//if there is no such page
                    b = 0;
                    int j = 0;
                    while (page_frame[j].number != -1) {//finding empty page
                        j++;
                    }
                    page_frame[j].number = in[i][1];
                    page_frame[j].counter = 0;
                    page_frame[j].last_cycle_used = in[i][0];
                }else{//if there is such page
                    b = 1;
                    page_frame[memory].last_cycle_used = in[i][0];
                }
            }
            //counter+=b;
        }else{//if a new cycle started
            int old_cycle = in[i-1][0];
            for (int j = 0; j < n; ++j) {//assigning new counter to each page
                if(page_frame[j].last_cycle_used == old_cycle){
                    page_frame[j].counter = (page_frame[j].counter>>1)|(1<<7);
                }else{
                    page_frame[j].counter = (page_frame[j].counter>>1);
                }
            }
            //adding new page to the page frame

            int c = 0;//but before we should check if page is already in page frame
            int memory = -1;
            for (int j = 0; j < n; ++j) {
                if(page_frame[j].number == in[i][1]){
                    c++;
                    memory = j;
                }
            }

            if(c==0) {//if there is no such page
                b = 0;
                if (is_full(page_frame, n) == 1) {//if page frame is full, then search an element with the smallest counter and page number
                    int min = page_frame[0].counter;
                    int d = 0;//shows which page is needed to be evicted
                    for (int j = 0; j < n; ++j) {
                        if (page_frame[j].counter < min) {
                            min = page_frame[j].counter;//found min counter
                        }
                    }
                    int min_number = 99999;
                    for (int j = 0; j <
                                    n; ++j) {//searching for page with min number in case if we have several pages with the same min counter
                        if (page_frame[j].counter == min && page_frame[j].number < min_number) {
                            min_number = page_frame[j].number;
                            d = j;
                        }
                    }
                    //we have found the page to evict
                    page_frame[d].number = in[i][1];
                    page_frame[d].counter = 0;
                    page_frame[d].last_cycle_used = in[i][0];
                }else {//case if page frame is not full

                    int c = 0;//but before we should check if page is already in page frame
                    int memory = -1;
                    for (int j = 0; j < n; ++j) {
                        if(page_frame[j].number == in[i][1]){
                            c++;
                            memory = j;
                        }
                    }

                    if(c==0) {//if there is no such page
                        b = 0;
                        int j = 0;
                        while (page_frame[j].number != -1) {//fining empty page
                            j++;
                        }
                        page_frame[j].number = in[i][1];
                        page_frame[j].counter = 0;
                        page_frame[j].last_cycle_used = in[i][0];
                    }else{//if there is such page
                        b = 1;
                        page_frame[memory].last_cycle_used = in[i][0];
                    }
                }
                //counter+=b;
            }else{//if there is such page
                page_frame[memory].last_cycle_used = in[i][0];
                b = 1;
            }
            //counter += b;
        }
//        for (int j = 0; j < n; ++j) {
//            printf("%d, %d, %d\n", page_frame[j].number,page_frame[j].counter,page_frame[j].last_cycle_used);
//        }
//        printf("\n");
        counter+=b;
        printf("%d\n", b);
    }

    int i, j, count = 1;
    //Traverse the array
    for (i = 1; i < m; i++)      //hold an array element
    {
        for (j = 0; j < i; j++)
        {
            if (in[i][1] == in[j][1])    //Check for duplicate elements
            {
                break;             //If duplicate elements found then break
            }
        }
        if (i == j)
        {
            count++;     //increment the number of distinct elements
        }
    }

   // printf("res = %d, counter = %d\n", count, counter);
    printf("%f\n", (double)(counter)/((double )(m) - (double)(counter)));

}
