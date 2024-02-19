
#include <stdio.h>

unsigned int val = 10;
unsigned int *ptr = &val;

int main()
{
    printf("val = %i \n", val);
    *ptr = 20;
    printf("val after modfying = %i \n",val);
return 0 ;
}
