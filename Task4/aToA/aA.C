#include <stdio.h>

int main() {
    int num;
    char ch;
    printf("Enter a number: ");
    scanf("%d",&num);

    printf("Enter a character: ");
    scanf(" %c",&ch);
    if (num % 2 == 0) {
        printf("%c\n",ch);
    } else {
        if (ch >= 'a' && ch <= 'z') {
            printf("%c\n",ch - 'a' + 'A');
        } else if (ch >= 'A' && ch <= 'Z') {
            printf("%c\n",ch - 'A' + 'a');
        }
    }

    return 0;
}
