#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sale.h"

void getCurrentDate(char *dateBuffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateBuffer, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void saveSalesData(struct Sale sales[], int saleCount) {
    FILE *file = fopen("sales_data.txt", "w");
    if (!file) return;
    for (int i = 0; i < saleCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%d\n", sales[i].carId, sales[i].buyerName, sales[i].paymentMode,
                sales[i].date, sales[i].sellerName, sales[i].phone, sales[i].emiMonths);
    }
    fclose(file);
}

void loadSalesData(struct Sale sales[], int *saleCount) {
    FILE *file = fopen("sales_data.txt", "r");
    if (!file) return;
    *saleCount = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d\n", sales[*saleCount].carId, sales[*saleCount].buyerName,
                  sales[*saleCount].paymentMode, sales[*saleCount].date,
                  sales[*saleCount].sellerName, sales[*saleCount].phone,
                  &sales[*saleCount].emiMonths) == 7) {
        (*saleCount)++;
    }
    fclose(file);
}

void recordSale(struct Sale sales[], int *saleCount, struct Car cars[], int carCount, struct Seller seller) {
    struct Sale newSale;
    printf("Enter Car ID to sell: ");
    scanf("%s", newSale.carId);
    getchar();
    printf("Enter Buyer Name: ");
    fgets(newSale.buyerName, 50, stdin);
    newSale.buyerName[strcspn(newSale.buyerName, "\n")] = 0;
    printf("Enter Payment Mode (Cash/EMI/Card): ");
    scanf("%s", newSale.paymentMode);
    getchar();
    printf("Enter Buyer Phone Number: ");
    scanf("%s", newSale.phone);
    getchar();
    if (strcmp(newSale.paymentMode, "EMI") == 0) {
        printf("Enter EMI duration in months: ");
        scanf("%d", &newSale.emiMonths);
        getchar();
    } else {
        newSale.emiMonths = 0;
    }
    getCurrentDate(newSale.date);
    strcpy(newSale.sellerName, seller.name);
    sales[*saleCount] = newSale;
    (*saleCount)++;
    saveSalesData(sales, *saleCount);
    printf("Car sold successfully!\n");
}

void generateReport(struct Sale sales[], int saleCount) {
    printf("\nSales Report:\n");
    
    printf("| %-10s | %-15s | %-12s | %-10s | %-12s | %-10s |\n", "Car ID", "Buyer Name", "Payment Mode", "Date", "Seller", "Phone");
    
    for (int i = 0; i < saleCount; i++) {
        printf("| %-10s | %-15s | %-12s | %-10s | %-12s | %-10s |\n",
               sales[i].carId, sales[i].buyerName, sales[i].paymentMode,
               sales[i].date, sales[i].sellerName, sales[i].phone);
    }
    
}
