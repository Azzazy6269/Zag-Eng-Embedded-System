#include <stdio.h>
//chat gpt helped me
int main() {
    int num;
    scanf("%d",&num);
    int msb_position = 31;//Chat GPT
    while (!((num >> msb_position) & 1) && msb_position >= 0) {
        msb_position--;
    }
    for (int i = msb_position; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");

    return 0;
}
