#include <stdio.h>

int Set_Num (int num , int bit){
 int i= num & (1<<bit);
 return i;
}



int main(){
    int nnum,bbit;
    char operator;
    printf("Enter the number:");
    scanf("%d",&nnum);
    printf("Enter the number of the bit:");
    scanf("%d",&bbit);
    printf("Enter the operator");
    scanf("%c",&operator);
    switch (operator){
     case 's' :
      printf("%d" , Set_Num(nnum,bbit));
      break;
    }





    return 0;
}