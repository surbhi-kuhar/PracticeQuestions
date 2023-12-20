#include <stdio.h>

int bitwise_and(int a, int b) {
    return ~(~a | ~b);
}

int main() {
    
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    int result = bitwise_and(a, b);

    printf("Bitwise AND of %d and %d is %d\n", a, b, result);
    
   
    return 0;
}
