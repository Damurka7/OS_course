#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int value;
    struct LinkedList* next;
} head;

void append(int value){
    struct LinkedList *node = malloc(sizeof(struct LinkedList));

    struct LinkedList *last = &head;
    while (last->next!=NULL){
        last = last->next;
    }
    node->value = value;
    node->next = NULL;
    last->next = node;
}

void insert_node(int value, struct LinkedList* prev){
    struct LinkedList *node = malloc(sizeof(struct LinkedList));
    node->value = value;
    node->next = prev->next;
    prev->next = node;
}

void print_list(struct LinkedList node){
    while (node.next!=NULL){
        printf("%d, ", node.value);
        node = *node.next;
    }
    printf("%d \n", node.value);
}

void delete_node(struct LinkedList *node){
    if(node == &head){
        head.next = NULL;
        head.value = NULL;
        printf("you have deleted the whole list\n");
    }else {
        struct LinkedList *last = &head;
        while (last->next != &node && last->next != NULL) {
            last = last->next;
        }
        if (last->next == NULL) {
            printf("there is no such node\n");
        } else {
            last->next = node->next;
        }
    }
}

int main () {

    head.value = 5;
    append(4);
    append(3);
    append(10);
    insert_node(77, &head);
    struct LinkedList n;
    n.value = 4;
    //delete_node(&head);
    print_list(head);

    return 0;
}
