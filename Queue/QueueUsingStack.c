#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    size_t capacity;
    size_t size;
} Stack;

Stack* createStack(size_t capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;

    return stack;
}

int isFull(Stack* stack) {
    return stack->size == stack->capacity;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void push(Stack* stack, int c) {
    if (isFull(stack)) {
        stack->array = realloc(stack->array, 2 * stack->capacity * sizeof(int));
        stack->capacity = 2 * stack->capacity;
    }

    stack->array[stack->size++] = c;
}

void pop(Stack* stack){
    if(isEmpty(stack)) return ;
    
    --stack->size;
}

int peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->size-1];
}

typedef struct{
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(100);
    queue->stack2 = createStack(100);
    
    return queue;
}

void pushQueue(Queue* q, int x){
    push(q->stack1,x);
}

int deQueue(Queue*q){
    if(isEmpty(q->stack2)){
        while(!isEmpty(q->stack1)){
            push(q->stack2,peek(q->stack1));
            pop(q->stack1);
        }
    }
    
    return peek(q->stack2);
}

int popQueue(Queue*q){
    if(isEmpty(q->stack2)){
        while(!isEmpty(q->stack1)){
            push(q->stack2,peek(q->stack1));
            pop(q->stack1);
        }
    }
    
    
    int ans =  peek(q->stack2);
    pop(q->stack2);
    return ans;
}

bool queueEmpty(Queue*q){
    return isEmpty(q->stack1) && isEmpty(q->stack2);
}



int main()
{
    Queue* queue = createQueue();
    
    pushQueue(queue, 1);
    pushQueue(queue, 2);
    printf("Front: %d\n", deQueue(queue)); // Should print 1
    printf("Dequeue: %d\n", popQueue(queue)); // Should print 1
    printf("Front: %d\n", deQueue(queue)); // Should print 2
    printf("Dequeue: %d\n", popQueue(queue)); // Should print 1
    printf("Is empty: %s\n", queueEmpty(queue) ? "true" : "false"); // Should print false


    return 0;
}
