#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

void update(Item *product) {
    printf("Enter updated details for item %d:\n", product->id);
    printf("Enter name: ");
    scanf("%s", &(product->name));
    printf("Enter price: ");
    scanf("%f", &(product->price));
}

int main() {
    
    Item item1;

    item1.id = 1;
    strcpy(item1.name, "Example Item");
    item1.price = 10.99;

    printf("Initial details for item %d:\n", item1.id);
    printf("Name: %s\n", item1.name);
    printf("Price: %.2f\n", item1.price);

    update(&item1);

    printf("Updated details for item %d:\n", item1.id);
    printf("Name: %s\n", item1.name);
    printf("Price: %.2f\n", item1.price);

    return 0;
}
