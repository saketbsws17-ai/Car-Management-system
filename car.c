#include <stdio.h>
#include "car.h"

void showAvailability(struct Car cars[], int carCount) {
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("- ID: %s\n  Model: %s\n  Price: ₹%.2f\n  Details: %s\n\n", cars[i].id, cars[i].model, cars[i].price, cars[i].details);
    }
}
