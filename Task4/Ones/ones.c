#include <stdio.h>

int main() {
    unsigned int num;
    scanf("%u",&num);
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    printf("%d\n",count);
    return 0;
}
