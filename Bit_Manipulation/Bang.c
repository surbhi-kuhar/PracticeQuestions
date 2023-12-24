#include <stdio.h>

int bang(int x) {
  int tmp = (((~x + 1) | x) >> 31);
  return tmp + 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int result = bang(n);
    
    printf("bang(%d) = %d", n, result);

    return 0;
}
