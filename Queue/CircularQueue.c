#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    size_t capacity;
    size_t size;
    int front;
    int rear;
} Queue;

Queue* createQueue(size_t capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}

int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

bool enQueue(Queue* queue, int c) {
    
    if(queue->size==queue->capacity) return false;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = c;
    queue->size++;
    
    return true;
}

bool deQueue(Queue* queue){
    if(isEmpty(queue)) return false;
    
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
    
    return true;
}

int front(Queue* q){
    if(isEmpty(q)) return -1;
    
    return q->array[q->front];
}

int rear(Queue* q){
    if(isEmpty(q)) return -1;
    
    return q->array[q->rear];
}



int main()
{
    Queue* q = createQueue(5);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);
    printf("%d\n",front(q));
    deQueue(q);
    deQueue(q);
    printf("%d",rear(q));

    return 0;
}
