#include <stdio.h>

int main() {
    char word[100];
    printf("Enter a sentence: ");
    while (scanf("%s", word) == 1) {
        printf("%s\n", word);
    }
    return 0;
}
