
#include <stdio.h>

int Set_Num (int num , int bit){
 int i= num | (1<<bit);
 return i;
}


int Clear_Num (int num , int bit){
  int i= num | (~(1<<bit)) ;
  return i;
}


int Toggle_Num (int num , int bit){
   int i= num ^ (1<<bit) ;
   return i; 
}


int Read_Num (int num , int bit){
    int i= (num>>bit)&1;
    return i;
}

int main(){
    int nnum,bbit;
     int operator;
    printf("Enter the number:");
    scanf("%d",&nnum);
    printf("Enter the number of the bit:");
    scanf("%d",&bbit);
    printf("Enter the operator:");
    scanf(" %d",&operator);
    switch (operator){
     case 1 :
      printf("%d" , Set_Num(nnum,bbit));
      break;
     case 2 :
      printf("%d" , Clear_Num(nnum,bbit));
      break;
     case 3 :
      printf("%d" , Toggle_Num(nnum,bbit));
      break;
     case 4 :
      printf("%d" , Read_Num(nnum,bbit));
      break;
      
    }
    return 0;
}
