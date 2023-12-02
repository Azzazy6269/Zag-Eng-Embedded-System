#include <stdio.h>

int main() {

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n<0) {
        return 0;
    } else {
        int result = 1;
        int nn = n;
        while (n > 0) {
            result *= n;
            n--;
        }
        printf("%d! = %d\n",nn, result);
    }
    return 0;
}
