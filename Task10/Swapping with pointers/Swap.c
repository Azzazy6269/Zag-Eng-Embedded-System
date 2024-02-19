#include <stdio.h>

unsigned int x=11;
unsigned int y=22;
unsigned int z=33;

unsigned int *p=&x;
unsigned int *q=&y;
unsigned int *r=&z;

int main()
{
 printf("x=%i\n",x);
 printf("y=%i\n",y);
 printf("z=%i\n",z);
 printf("p=0x%X\n",p);
 printf("q=0x%X\n",q);
 printf("r=0x%X\n",r);
 printf("*p=%i\n",*p);
 printf("*q=%i\n",*q);
 printf("*r=%i\n\n",*r);
 printf("Swapping pointers\n\n");

 Swap(p,q,r);

 printf("x=%i\n",x);
 printf("y=%i\n",y);
 printf("z=%i\n",z);
 printf("p=0x%X\n",p);
 printf("q=0x%X\n",q);
 printf("r=0x%X\n",r);
 printf("*p=%i\n",*p);
 printf("*q=%i\n",*q);
 printf("*r=%i\n",*r);
return 0;
}


void Swap(unsigned int *num1,unsigned int *num2,unsigned int *num3){
    unsigned int temp = *num1;
    *num1 = *num2;
    *num2 = *num3;
    *num3 = temp;

}
