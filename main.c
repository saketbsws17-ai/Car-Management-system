#include <stdio.h>
#include "car.c"
#include "sale.c"
#include "seller.c"

int main() {
    struct Seller currentSeller;
    struct Car cars[] = {
        {"CAR001", "Honda City", 1200000.00, "Sedan, Petrol, 1497cc, 17.8 km/l"},
        {"CAR002", "Hyundai Creta", 1500000.00, "SUV, Diesel, 1493cc, 21.4 km/l"},
        {"CAR003", "Maruti Swift", 800000.00, "Hatchback, Petrol, 1197cc, 22 km/l"},
        {"CAR004", "Toyota Fortuner", 4200000.00, "SUV, Diesel, 2755cc, 14.2 km/l"},
        {"CAR005", "Tata Nexon", 1200000.00, "Compact SUV, Petrol, 1199cc, 17.4 km/l"},
        {"CAR006", "Kia Seltos", 1400000.00, "SUV, Diesel, 1493cc, 19.8 km/l"},
        {"CAR007", "Mahindra XUV700", 2500000.00, "SUV, Diesel, 2198cc, 15.5 km/l"},
        {"CAR008", "Skoda Slavia", 1600000.00, "Sedan, Petrol, 1498cc, 18.7 km/l"},
        {"CAR009", "Volkswagen Taigun", 1700000.00, "SUV, Petrol, 1498cc, 18.1 km/l"},
        {"CAR010", "MG Hector", 1800000.00, "SUV, Diesel, 1956cc, 16.6 km/l"}
    };

    struct Sale sales[100];
    int saleCount = 0;
    loadSalesData(sales, &saleCount);

    while (1) {
        sellerLogin(&currentSeller);
        int choice;
        do {
            printf("\n1. Show Available Cars\n2. Record Sale\n3. Generate Report\n4. Logout\nEnter choice: ");
            scanf("%d", &choice);
            getchar();
            switch (choice) {
                case 1: showAvailability(cars, 10); break;
                case 2: recordSale(sales, &saleCount, cars, 10, currentSeller); break;
                case 3: generateReport(sales, saleCount); break;
                case 4: printf("Logging out...\n"); break;
                default: printf("Invalid choice. Try again.\n");
            }
        } while (choice != 4);
    }

    return 0;
}
