#include <stdio.h>
#include <stdlib.h>

struct NodeOfLinkedList {
    int value;
    struct NodeOfLinkedList* next;
} head;

void append(int value){
    struct NodeOfLinkedList *node = malloc(sizeof(struct NodeOfLinkedList));

    struct NodeOfLinkedList *last = &head;
    while (last->next!=NULL){
        last = last->next;
    }
    node->value = value;
    node->next = NULL;
    last->next = node;
}

void insert_node(int value, struct NodeOfLinkedList* prev){
    struct NodeOfLinkedList *node = malloc(sizeof(struct NodeOfLinkedList));
    node->value = value;
    node->next = prev->next;
    prev->next = node;
}

void print_list(struct NodeOfLinkedList *node){
    while (node->next!=NULL){
        printf("%d, ", node->value);
        node = node->next;
    }
    printf("%d \n", node->value);
}

void delete_node(struct NodeOfLinkedList *node){
    if(node == &head){
        head.next = NULL;
        head.value = NULL;
        printf("you have deleted the whole list\n");
    }else {
        struct NodeOfLinkedList *last = &head;
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
    struct NodeOfLinkedList n;
    n.value = 4;
    delete_node(&head);
    print_list(&head);

    return 0;
}
