#include <stdio.h>

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int result = bang(n);
    
    printf("bang(%d) = %d", n, result);

    return 0;
}
