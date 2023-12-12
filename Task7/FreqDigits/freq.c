#include <stdio.h>
#include <string.h>
//chat gpt helped me
int main() {
    char input[100];
    int digitCount[10] = {0};

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            int digit = input[i] - '0';
            digitCount[digit]++;
        }
    }

    printf("Frequency of each digit: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d", digitCount[i]);
    }
    printf("\n");

    return 0;
}
