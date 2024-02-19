#include <stdio.h>

unsigned int x,y;
static int Sub;
static int Sum;

int main()
{
    printf("Enter two values");
    scanf("%i%i",&x,&y);
    Calc(x,y,&Sum,&Sub);
    printf("Summation = %i\n",Sum);
    printf("Substract = %i\n",Sub);
return 0;
}

void Calc(int num1 ,int num2 ,int *SumResult , int *SubResult ){
   *SumResult = num1 + num2 ;
   if (num1>num2){
        *SubResult = num1 - num2 ;
   }else {*SubResult = num2 - num1 ;}


}
