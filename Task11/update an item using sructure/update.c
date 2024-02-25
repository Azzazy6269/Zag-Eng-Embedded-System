#include <stdio.h>

// Define the structure Item
typedef struct {
    int id;
    char name[50];
    float price;
} Item;

// Function to update an item
void update(Item *product) {
    printf("Enter updated details for item %d:\n", product->id);
    printf("Enter name: ");
    scanf("%s", product->name);
    printf("Enter price: ");
    scanf("%f", &product->price);
}

int main() {
    // Create an instance of the Item structure
    Item item1;

    // Initialize the item with some values
    item1.id = 1;
    strcpy(item1.name, "Example Item");
    item1.price = 10.99;

    // Display the initial values of the item
    printf("Initial details for item %d:\n", item1.id);
    printf("Name: %s\n", item1.name);
    printf("Price: %.2f\n", item1.price);

    // Call the update function to modify the item
    update(&item1);

    // Display the updated values of the item
    printf("Updated details for item %d:\n", item1.id);
    printf("Name: %s\n", item1.name);
    printf("Price: %.2f\n", item1.price);

    return 0;
}
