#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PropertySale {
    int UID;
    char Address[100];
    char ZIP_Code[10];
    int Size;
    int Construction_Year;
    double Price;
    struct PropertySale* next;
} PropertySale;

typedef struct {
    PropertySale* head;
} SalesDatabase;

void initDatabase(SalesDatabase* db) {
    db->head = NULL;
}

void Sales(SalesDatabase* db, int UID, const char* Address, const char* ZIP_Code, int Size, int Construction_Year, double Price) {
    PropertySale* newSale = (PropertySale*)malloc(sizeof(PropertySale));
    newSale->UID = UID;
    strcpy(newSale->Address, Address);
    strcpy(newSale->ZIP_Code, ZIP_Code);
    newSale->Size = Size;
    newSale->Construction_Year = Construction_Year;
    newSale->Price = Price;
    newSale->next = db->head;
    db->head = newSale;
}

void Erase(SalesDatabase* db, int UID) {
    PropertySale* current = db->head;
    PropertySale* previous = NULL;
    while (current != NULL && current->UID != UID) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Property with UID %d not found.\n", UID);
        return;
    }
    if (previous == NULL) {
        db->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Property with UID %d has been removed.\n", UID);
}

PropertySale* Search(SalesDatabase* db, int UID) {
    PropertySale* current = db->head;
    while (current != NULL) {
        if (current->UID == UID)
            return current;
        current = current->next;
    }
    return NULL;
}

void PrintDB(SalesDatabase* db) {
    PropertySale* current = db->head;
    while (current != NULL) {
        printf("UID: %d | Address: %s | ZIP Code: %s | Size: %d sq ft | Year: %d | Price: $%.2f\n",
               current->UID, current->Address, current->ZIP_Code, current->Size, current->Construction_Year, current->Price);
        current = current->next;
    }
}

const char* GetZIP(SalesDatabase* db, int UID) {
    PropertySale* sale = Search(db, UID);
    return sale ? sale->ZIP_Code : "Not Found";
}

double GetPrice(SalesDatabase* db, int UID) {
    PropertySale* sale = Search(db, UID);
    return sale ? sale->Price : -1.0;
}

int SalesCount(SalesDatabase* db) {
    int count = 0;
    PropertySale* current = db->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

double AveragePrice(SalesDatabase* db) {
    if (db->head == NULL) return 0.0;
    double total = 0;
    int count = 0;
    PropertySale* current = db->head;
    while (current != NULL) {
        total += current->Price;
        count++;
        current = current->next;
    }
    return count ? total / count : 0.0;
}

void FreeDatabase(SalesDatabase* db) {
    while (db->head) {
        PropertySale* temp = db->head;
        db->head = db->head->next;
        free(temp);
    }
}

int main() {
    SalesDatabase db;
    initDatabase(&db);
    Sales(&db, 101, "123 Main St", "10001", 1200, 2015, 250000);
    Sales(&db, 102, "456 Elm St", "10002", 1500, 2018, 320000);
    Sales(&db, 103, "789 Oak St", "10003", 1000, 2020, 280000);

    printf("All Sales:\n");
    PrintDB(&db);

    printf("\nSearching for property with UID 102:\n");
    PropertySale* found = Search(&db, 102);
    if (found) {
        printf("Found property at %s\n", found->Address);
    } else {
        printf("Property not found.\n");
    }

    printf("\nAverage Price of all sales: $%.2f\n", AveragePrice(&db));
    printf("Total Sales Count: %d\n", SalesCount(&db));

    Erase(&db, 102);
    printf("\nDatabase after deletion:\n");
    PrintDB(&db);

    FreeDatabase(&db);
    return 0;
}
