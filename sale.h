#ifndef SALE_H
#define SALE_H

#include "car.h"
#include "seller.h"

struct Sale {
    char carId[10];
    char buyerName[50];
    char paymentMode[20];
    char date[20];
    char phone[15];
    char sellerName[50];
    int emiMonths;
};

void recordSale(struct Sale sales[], int *saleCount, struct Car cars[], int carCount, struct Seller seller);
void generateReport(struct Sale sales[], int saleCount);
void saveSalesData(struct Sale sales[], int saleCount);
void loadSalesData(struct Sale sales[], int *saleCount);

#endif

