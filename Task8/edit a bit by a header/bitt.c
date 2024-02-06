#include <stdio.h>
#include "bitt.h"

int main() {
    unsigned int myVar = 5;  

    Set_Bit(myVar, 2);
    printf("After setting bit 2: %u\n", myVar);

    Clr_Bit(myVar, 1);
    printf("After clearing bit 1: %u\n", myVar);

    Toggle_Bit(myVar, 0);
    printf("After toggling bit 0: %u\n", myVar);

    return 0;
}
