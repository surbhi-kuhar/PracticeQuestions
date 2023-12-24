#include <stdio.h>

int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {
    int num ;
    int shiftAmount;
    
    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter shift amount: ");
    scanf("%d", &shiftAmount);

    int result = logicalShift(num, shiftAmount);
    printf("Result after logical shift: %d\n", result);

    return 0;
}


