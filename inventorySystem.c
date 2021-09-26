//
// Created by juode on 29/06/21.
//

#include "stdio.h"

struct Item {
    int num, rate, quantity;
    char name[20];
};

void main() {

    struct Item item;
    int choice;

    FILE *file = fopen("inventoryData.bin", "wb+");

    for (int i = 0; i < 5; i++) {
        printf("Enter item %d details : \n", i+1);
        item.num = i+1;
        printf("\tName : ");
        scanf("%s", item.name);
        printf("\tRate : ");
        scanf("%d", &item.rate);
        printf("\tQuantity : ");
        scanf("%d", &item.quantity);

        fwrite(&item, sizeof(struct Item), 1, file);
    }
    rewind(file);

    printf("\nItems in the inventory are,");
    for (int i = 0; i < 5; i++) {
        fread(&item, sizeof(struct Item), 1, file);
        printf("\n%d.\t%s\t%d\t%d", item.num, item.name, item.rate, item.quantity);
    }

    int exit = 0;
    while (exit!=1) {
        printf("\nChoices available, ");
        printf("\n\t1 -> Update an Item");
        printf("\n\t2 -> Quit the program");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        int number, newQuantity;
        switch (choice) {
            case 1:
                printf("Enter item Number : ");
                scanf("%d", &number);
                printf("Enter available quantity : ");
                fseek(file, sizeof(struct Item) * (number - 1), 0);
                scanf("%d", &newQuantity);
                item.quantity = newQuantity;
                printf("\nAfter updating the items...");
                rewind(file);
                printf("\nItems in the inventory are,");
                for (int i = 0; i < 5; ++i) {
                    fread(&item, sizeof(struct Item), 1, file);
                    printf("\n%d.\t%s\t%d\t%d", item.num, item.name, item.rate, item.quantity);
                }
                break;
            case 2:
                exit = 1;
                break;
            default:
                printf("Invalid choice!");
        }
    }

    fclose(file);

}
