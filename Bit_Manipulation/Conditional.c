#include <stdio.h>

int conditional(int x, int y, int z) {
    int mask = ((!x) + ~0) >> 31;  
    return (y & mask) | (z & ~mask);
}

int main() {

    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int result = conditional(a,b,c); 
    
    printf("conditional(%d, %d, %d) = %d\n", a,b,c,result);
    return 0;
}