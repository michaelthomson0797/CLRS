#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int key;
};

struct Node* find(struct Node** head, int key) {
    struct Node* x = (*head);

    while(x->key != key && x != NULL) {
        x = x->next;
    }

    return x;
}

int insert(struct Node** head, int key)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->next = (*head);
    new_node->prev = NULL;
    new_node->key = key;

    if((*head) != NULL) {
        (*head)->prev = new_node;
    }

    (*head) = new_node;
}

void delete(struct Node** head, int key)
{
    struct Node* x = find(head, key);
    if(x == NULL) {
        return;
    }
    if(x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        *head = x->next;
    }
    if(x->next != NULL) {
       x->next->prev = x->prev;
    }
    return;
}

void printLinkedList(struct Node* head) 
{
    for(struct Node* x = head; x != NULL; x = x->next) {
        printf("%d ", x->key);
    }
    printf("\n");
}
