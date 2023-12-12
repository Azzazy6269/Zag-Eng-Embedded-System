#include <stdio.h> 
#include <limits.h>


int main (){
    int x[3],min=INT_MAX,max;
    for (int i=0;i<3;i++){
        scanf("%d",&x[i]);
        if (x[i]<min)
         min = x[i];
        if (x[i]>max)
         max = x[i];
    }
    printf("min = %d\n max = %d",min,max);
    return 0;

}