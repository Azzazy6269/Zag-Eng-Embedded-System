#include <stdio.h>

int main() {
    int A,B
    printf("Enter number A: ");
    scanf("%d", &A);
    printf("Enter number B: ");
    scanf("%d", &B);

    if (B < A) {
        for (int i = A; i <= B; i--) {
            printf("%d\n", i);
        }
    } else {
        for (int i = A; i <= B; i++) {
            printf("%d\n", i);
        }
    }

    return 0;
}
