typedef struct {
    char* array;
    size_t capacity;
    size_t size;
} Stack;

Stack* createStack(size_t capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->array = (char*)malloc(capacity * sizeof(char));
    stack->size = 0;

    return stack;
}

int isFull(Stack* stack) {
    return stack->size == stack->capacity;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void push(Stack* stack, char c) {
    if (isFull(stack)) {
        stack->array = realloc(stack->array, 2 * stack->capacity * sizeof(char));
        stack->capacity = 2 * stack->capacity;
    }

    stack->array[stack->size++] = c;
}

void pop(Stack* stack){
    if(isEmpty(stack)) return ;
    
    --stack->size;
}

char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->size-1];
}

bool isValidParentheses(char* s){
    
    Stack* stack = createStack(100);
    
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') push(stack,s[i]);
        else if(s[i]==')'){
            if(!isEmpty(stack) && peek(stack)=='('){
                pop(stack);
            }
            else return false;
            
        }
        
        else if(s[i]=='}'){
            if(!isEmpty(stack) && peek(stack)=='{'){
                pop(stack);
            }
            else return false;
            
        }
        
        else if(s[i]==']'){
            if(!isEmpty(stack) && peek(stack)=='['){
                pop(stack);
            }
            else return false;
            
        }
    }
    
    if(!isEmpty(stack)) return false;
    
    return true;
    
}

bool isValid(char* s) {
    if(isValidParentheses(s)) return true;
    return false;
}