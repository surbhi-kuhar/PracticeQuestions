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

int longestValidParentheses(char* s) {
    Stack* st = createStack(100);
    push(st,-1);
    int ans = 0;

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='(') push(st,i);
        else{
            if(st->size==1) st->array[st->size-1] = i;
            else{
                pop(st);
                if(i-peek(st) > ans){
                    ans = i-peek(st);
                }
            }
        }
    }

    return ans;
}