#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};
void addItem() {
    struct Item it;
    FILE *fp = fopen("inventory.dat", "ab");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Item ID: ");
    scanf("%d", &it.id);
    printf("Enter Item Name: ");
    scanf("%s", it.name);
    printf("Enter Price: ");
    scanf("%f", &it.price);
    printf("Enter Quantity: ");
    scanf("%d", &it.quantity);
    fwrite(&it, sizeof(it), 1, fp);
    fclose(fp);
    printf("✅ Item added successfully!\n");
}
void viewItems() {
    struct Item it;
    FILE *fp = fopen("inventory.dat", "rb");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("\n===== INVENTORY ITEMS =====\n");
    while (fread(&it, sizeof(it), 1, fp)) {
        printf("🆔 %d | 📦 %s | 💰 %.2f | 📊 Qty: %d\n",
               it.id, it.name, it.price, it.quantity);
    }
    fclose(fp);
}
void updateStock() {
    struct Item it;
    int id, qty, found = 0;
    FILE *fp = fopen("inventory.dat", "rb+");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Item ID: ");
    scanf("%d", &id);
    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &qty);
            it.quantity = qty;
            fseek(fp, -sizeof(it), SEEK_CUR);
            fwrite(&it, sizeof(it), 1, fp);
            printf("✅ Stock updated!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Item not found.\n");
    fclose(fp);
}
void sellItem() {
    struct Item it;
    int id, qty, found = 0;
    FILE *fp = fopen("inventory.dat", "rb+");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Item ID: ");
    scanf("%d", &id);
    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id == id) {
            printf("Enter quantity to sell: ");
            scanf("%d", &qty);
            if (it.quantity >= qty) {
                it.quantity -= qty;
                fseek(fp, -sizeof(it), SEEK_CUR);
                fwrite(&it, sizeof(it), 1, fp);
                printf("✅ Sold successfully! Total: %.2f\n", it.price * qty);
            } else {
                printf("❌ Not enough stock.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Item not found.\n");
    fclose(fp);
}
int main() {
    int choice;
    printf("\n===== INVENTORY SYSTEM =====\n");
    printf("1. Add Item\n2. View Items\n3. Update Stock\n4. Sell Item\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: addItem(); break;
        case 2: viewItems(); break;
        case 3: updateStock(); break;
        case 4: sellItem(); break;
        default: printf("❌ Invalid choice.\n");
    }
    return 0;
}