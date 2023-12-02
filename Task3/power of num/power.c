#include <stdio.h>
int main() {
    int base,exponent,x;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    x=1;
    for (int i = 0; i <exponent; i++)
    {
        x=base*x;
    }
    
    printf("the result=%d",x);

    return 0;
}