#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Account {
    int acc_no;
    char name[50];
    float balance;
};
void createAccount() {
    struct Account acc;
    FILE *fp = fopen("bank.dat", "ab");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    acc.balance = 0.0;
    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);
    printf("✅ Account created successfully!\n");
}
void depositMoney() {
    struct Account acc;
    int acc_no, found = 0;
    float amt;
    FILE *fp = fopen("bank.dat", "rb+");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amt);
            acc.balance += amt;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("✅ Deposit successful!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Account not found.\n");
    fclose(fp);
}
void withdrawMoney() {
    struct Account acc;
    int acc_no, found = 0;
    float amt;
    FILE *fp = fopen("bank.dat", "rb+");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);
            if (acc.balance >= amt) {
                acc.balance -= amt;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("✅ Withdrawal successful!\n");
            } else {
                printf("❌ Insufficient balance.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Account not found.\n");
    fclose(fp);
}
void checkBalance() {
    struct Account acc;
    int acc_no, found = 0;
    FILE *fp = fopen("bank.dat", "rb");
    if (!fp) { printf("❌ File error.\n"); return; }
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("👤 Name: %s | 💰 Balance: %.2f\n", acc.name, acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Account not found.\n");
    fclose(fp);
}
int main() {
    int choice;
    printf("\n===== BANKING SYSTEM =====\n");
    printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: createAccount(); break;
        case 2: depositMoney(); break;
        case 3: withdrawMoney(); break;
        case 4: checkBalance(); break;
        default: printf("❌ Invalid choice.\n");
    }
    return 0;
}