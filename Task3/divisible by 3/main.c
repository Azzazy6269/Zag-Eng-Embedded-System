#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<5 ;i++){
    int x;
    scanf("%d",&x);
    if(x%3 == 0){
        printf("%d is Divisble by 3",x);
    }else{
        printf("%d is not Divisible by 3",x);
    }

    }
    return 0;
}
