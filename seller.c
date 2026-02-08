#include <stdio.h>
#include <string.h>
#include "seller.h"

struct Seller sellers[] = {
    {"RAJIV123", "Rajiv Sharma", "password"},
    {"AMANP456", "Aman Patel", "password"},
    {"PRIYA789", "Priya Verma", "password"},
    {"ANUSH567", "Anusha Reddy", "password"}
};

int sellerLogin(struct Seller *seller) {
    char enteredId[10], enteredPassword[20];
    while (1) {
        printf("Enter Seller ID: ");
        scanf("%s", enteredId);
        printf("Enter Password: ");
        scanf("%s", enteredPassword);
        for (int i = 0; i < 4; i++) {
            if (strcmp(enteredId, sellers[i].id) == 0 && strcmp(enteredPassword, sellers[i].password) == 0) {
                *seller = sellers[i];
                printf("Login successful!\n");
                return 1;
            }
        }
        printf("Invalid login. Try again.\n");
    }
}