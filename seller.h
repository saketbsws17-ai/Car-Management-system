#ifndef SELLER_H
#define SELLER_H

struct Seller {
    char id[10];
    char name[50];
    char password[20];
};

int sellerLogin(struct Seller *seller);

#endif