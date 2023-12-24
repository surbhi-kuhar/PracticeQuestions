#include <stdio.h>

int sign(int x) 
{ 
    return (x >> 31) | (!(!x)); 
}

int main() {
    
    int num ;
    scanf("%d",&num);
    int result = sign(num);
    
    printf("sign(%d) = %d \n",num, result);

    return 0;
}
