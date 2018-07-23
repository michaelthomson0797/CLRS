#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Structure for stacks
struct Stack
{
    int top;
    int capacity;
    int* A;
};

// function to initialize and return a stack of a specified capacity
struct Stack* initStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->A = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// returns true is the stack is empy, false otherwise
int isEmpty(struct Stack* stack) 
{   return stack->top == -1; }

// returns true is the stack is full, false otherwise
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity-1; }

// adds an element to the top of the stack
void push(struct Stack* stack, int item)
{
    if(isFull(stack)) {
        return;
    }
    stack->top = stack->top + 1;
    stack->A[stack->top] = item;
}

// removed and returns an element from the top of the stack
int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    } else {
        stack->top = stack->top - 1;
        return stack->A[stack->top+1];
    }
}

// helper function to showcase functionality
int main() {
    struct Stack* stack = initStack(7);
    push(stack,15);
    push(stack,6);
    push(stack,2);
    push(stack,9);
    push(stack,17);
    push(stack,3);
    
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
}
