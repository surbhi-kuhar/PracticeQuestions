#include <stdio.h>

int sign(int i)
{
	return 1 + (i >> 31) - (-i >> 31);
}


int main() {
    
    int num ;
    scanf("%d",&num);
    int result = sign(num);
    
    if(result==0){
        printf("sign(%d) = -1 \n",num);
    }
    else if(result==1){
        printf("sign(%d) = 0 \n",num);
    }
    else if(result==2){
        printf("sign(%d) = 1 \n",num);
    }

    return 0;
}
