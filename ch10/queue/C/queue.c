#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue
{
    int tail;
    int head;
    int capacity;
    int* array;
};

struct Queue* initQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->tail = 0;
    queue->head = 0;
    queue->capacity = capacity;
    queue->array = (int*) malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue)
{   return queue->head == queue->tail; }

int isFull(struct Queue* queue)
{   return (queue->head == queue->tail+1) || (queue->head == 0 && queue->tail == queue->capacity-1); }

int enqueue(struct Queue* queue, int x)
{ 
    if(isFull(queue)) {
        return;
    }
    queue->array[queue->tail] = x;
    if(queue->tail == queue->capacity-1) {
        queue->tail = 0;
    } else {
        queue->tail++;
    }
}

int dequeue(struct Queue* queue)
{
    if(isEmpty(queue)) {
        return;
    }
    int x = queue->array[queue->head];
    if(queue->head == queue->capacity-1) {
        queue->head = 0;
    } else {
        queue->head++;
    }
    return x;
}

int main() {
    struct Queue* queue = initQueue(12);
    
    enqueue(queue,15);
    enqueue(queue,6);
    enqueue(queue,9);
    enqueue(queue,8);
    enqueue(queue,4);
    enqueue(queue,17);
    enqueue(queue,3);
    enqueue(queue,5);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
}
