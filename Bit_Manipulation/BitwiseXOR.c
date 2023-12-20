#include <stdio.h>

int bitwise_xor(int a, int b) {
    return ~(~a & ~b) & ~(a & b);
}

int main() {
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    int result = bitwise_xor(a, b);

    printf("Bitwise XOR of %d and %d is %d\n", a, b, result);

    return 0;
}