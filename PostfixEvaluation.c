#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
    
    
    int postFixEvaluation(char* s){
        Stack* stack = createStack(100);
        
        for(int i=0; s[i]!='\0';i++){
            if(s[i]>='0' && s[i]<='9') push(stack,s[i]-'0');
            else{
                int top1 = peek(stack);
                pop(stack);
                int top2 = peek(stack);
                pop(stack);
                
                if (s[i] == '+') {
                    push(stack, top2 + top1);
                } else if (s[i] == '-') {
                    push(stack, top2 - top1);
                } else if (s[i] == '*') {
                    push(stack, top2 * top1);
                } else if (s[i] == '/') {
                    push(stack, top2 / top1);
                }
            }
        }
        
        return peek(stack);
    }

int main() {

    char*c =  "231*+9-";
    printf("%d\n",postFixEvaluation(c));
    
    char*d =  "123+*8-";
    printf("%d",postFixEvaluation(d));
    
    return 0;
}
