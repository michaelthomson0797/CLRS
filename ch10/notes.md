# Chapter 10: Elementary Data Structures

## 10.1 Stacks and Queues
* Stacks and Queues are dynamic sets in which the element removed from the set by the delete operation is prespecified.
* In a **stack**, the element deleted from the set is the one most recently inserted:
    * the stack implements a **last-in, first-out** or **LIFO** policy.
* In a queue, the element deleted us always the one that has been in the set for the longest time:
    * The queue implements a **first-in, first-out** or FIFO policy.

### Stack
* The insert operation on a stack is often called push and the delete operation is called pop.
* This is done using a variable S.top that indexes the most recently inserted element.
* if S.top = 0, the stack is empty, which is determined by the stackEmpty function

```c
int stackEmpty(struct Stack* stack) {
    if(S->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct Stack* stack, int x) {
    S->top = S->top + 1;
    S->A[S->top] = x;
}

int pop(struct Stack* stack) {
    if(stackEmpty(stack) == 1) {
        return INT_MIN;
    } else {
        return S->A[S->top+1];
    }
}
```
### Queues
* We call the insert operation enqueue, and the delete operation dequeue
* The FIFO property of a queue causes it to operate like a line of customers
* The queue has a **head** and a **tail**
* When an element is queued, it takes its place at the tail of the queue
* the element dequeued is always the one at the head of the queue
* when head = tail, the queue is empty.
* when head = tail+1, or both head = 1 and tail = length, the queue is full

```c
int isEmpty(struct Queue* queue)
{   return queue->head == queue->tail; }

int isFull(struct Queue* queue)
{   return (queue->head == queue->tail+1) || (queue->head == 0 && queue->tail == queue.capacity-1; }

int enqueue(struct Queue* queue, int x)
{ 
    if(isFull(queue)) {
        return;
    }
    queue->array[queue->tail] = x;
    if(queue->tail == queue->capacity) {
        queue->tail = 0;
    } else {
        queue->tail++;
    }
}

int dequeue(struct Queue* queue, int x)
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
``` 
