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

int delete(struct Node** head, int key)
{
    struct Node* x = find(head, key);
    if(x == NULL) {
        return 0;
    }
    x->prev->next = x->next;
    x->next->prev = x->prev;
    return 1;
}

void printLinkedList(struct Node* head) 
{
    for(struct Node* x = head; x != NULL; x = x->next) {
        printf("%d ", x->key);
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    
    /* testing insertion */
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    printLinkedList(head);

    /* testing deletion */
    delete(&head, 4);
    delete(&head, 3);
    printLinkedList(head);
}

