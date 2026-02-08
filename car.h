#ifndef CAR_H
#define CAR_H

struct Car {
    char id[10];
    char model[50];
    float price;
    char details[500];
};

void showAvailability(struct Car cars[], int carCount);

#endif