#include <stdio.h>

int pin = 1234;
float balance = 1000;

void checkBalance() {
    printf("Current Balance: %.2f\n", balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if(amount > 0) {
        balance += amount;
        printf("Amount deposited successfully!\n");
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if(amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Please collect your cash.\n");
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

int main() {
    int enteredPin, choice;

    printf("Welcome to ATM Machine\n");
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if(enteredPin != pin) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0;
    }

    printf("PIN verified successfully!\n");

    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: checkBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: printf("Thank you for using ATM!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
