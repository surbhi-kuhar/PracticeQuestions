#include <stdio.h>

int conditional(int x, int y, int z) {
  int a = (x >> 31) | ((~x + 1) >> 31);
  return ((a & y) + (~a & z));
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