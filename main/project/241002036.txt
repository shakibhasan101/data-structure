#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Created a structure
struct PropertySale {
    int UIU;
    char address[100];
    int zip;
    float size;
    int year;
    double price;
    struct PropertySale *nextNode;
};
//created database called SalesDatabase
struct PropertySale* SalesDatabase(int UIU, char address[], int zip, float size, int year, double price)

    {

        struct PropertySale *nn = (struct PropertySale*) malloc(sizeof(struct PropertySale));
        if (nn == NULL) return NULL;

        nn->UIU = UIU;
        strcpy(nn->address, address);
        nn->zip = zip;
        nn->size = size;
        nn->year = year;
        nn->price = price;
        nn->nextNode = NULL;

    return nn;
    }

//sales function to insert data in the linked list
void Sales(struct PropertySale** head) {
        int UIU;
        char address[100];
        int zip;
        float size;
        int year;
        double price;

    printf("Enter the UIU:\n");
    scanf("%d", &UIU);
    printf("Enter the Address:\n");
    scanf("%99s", address);
    printf("Enter the ZIP Code:\n");
    scanf("%d", &zip);
    printf("Enter the Size of Land:\n");
    scanf("%f", &size);
    printf("Enter the Construction Year:\n");
    scanf("%d", &year);
    printf("Enter the Price:\n");
    scanf("%lf", &price);


    struct PropertySale* nn = SalesDatabase(UIU, address, zip, size, year, price);
    if (nn == NULL) return;
    //if there is no node
    if (*head == NULL ) {
        nn->nextNode = *head;
        *head = nn;
        return;
    }
    //if there is at least 1 node
    struct PropertySale* cn = *head;
    struct PropertySale* pn = NULL;
    int i = 0;

    while (cn != NULL) {
        pn = cn;
        cn = cn->nextNode;
        i++;
    }

    pn->nextNode = nn;
    nn->nextNode = cn;
}


//Delete an entry from the database based on the UID.
void Erase(struct PropertySale **head) {
    int UIU;
    printf("Enter UIU to delete:");
    scanf("%d", &UIU);
    //if there is no node
    if (*head == NULL) return;

    struct PropertySale* cn = *head;
    struct PropertySale* pn = NULL;
    //if there is a node
    if (cn != NULL && cn->UIU == UIU) {
        *head = cn->nextNode;
        free(cn);
        return;
    }
    //if there is more than one node

    while (cn != NULL && cn->UIU != UIU) {
        pn = cn;
        cn = cn->nextNode;
    }

    if (cn == NULL) {
        printf("Property with UIU %d is not found.\n", UIU);
        return;
    }

    pn->nextNode = cn->nextNode;
    free(cn);
}

//Search function help to  find an entry in the database by UIU.

void Search(struct PropertySale *head) {
    int UIU;

    printf("Enter UIU to search property:\n");
    scanf("%d", &UIU);
    //if there is no node
    if (head == NULL) {
        printf("Database is Empty\n");
        return;
    }

    struct PropertySale* cn = head;
    while (cn != NULL) {
        if (cn->UIU == UIU) {
            printf("Property Found:\n");
            printf("UIU: %d\n", cn->UIU);
            printf("Address: %s\n", cn->address);
            printf("ZIP Code: %d\n", cn->zip);
            printf("Size: %.2f\n", cn->size);
            printf("Year: %d\n", cn->year);
            printf("Price: %.2lf\n", cn->price);
            return;
        }
        cn = cn->nextNode;
    }

    printf("Property with UIU %d not found.\n", UIU);
}

//PrintDB function print one or all elements from the database.
//User can choice whether he want to see all or data or a specific one.

  void PrintDB(struct PropertySale *head) {

    char choice;

    printf("type Y/y to see a data of a specific property\n");
    printf("type N/n to see the Entire Database");
    printf("Do you want to print a specific property by UIU? (y/n): ");

    scanf(" %c", &choice);

    //A specific data will print
    if (choice == 'y' || choice == 'Y')
        Search(head);
    //Entire Database will display
    else if (choice == 'n' || choice == 'N')

        {
            if (head == NULL)
                {
                    printf("The database is empty.\n");
                    return;
                }

            printf("Printing all properties in the database:\n");

            struct PropertySale* cn = head;

            while (cn != NULL)

                {
                printf("UIU: %d, Address: %s, ZIP Code: %d, Size: %.2f, Year: %d, Price: %.2f\n",
                       cn->UIU, cn->address, cn->zip, cn->size, cn->year, cn->price);

                cn = cn->nextNode;
                }
        }

    //for Wrong input
    else
        {
        printf("Invalid choice! Please enter 'y' for specific property or 'n' for all properties.\n");
        }
}


//This GetZIP function helps the user to find the ZIP code based on the UIU

void GetZIP(struct PropertySale *head) {

    int UIU;

    printf("Enter UIU to retrieve the ZIP code of a flat:\n");
    scanf("%d", &UIU);

    //if there is no node
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }
    //if there is a node

    struct PropertySale* cn = head;
    while (cn != NULL) {
        if (cn->UIU == UIU) {
            printf("The ZIP code for the property with UIU %d is: %d\n", UIU, cn->zip);
            return;
        }
        cn = cn->nextNode;
    }

    printf("Property with UIU %d not found.\n", UIU);
}
//This GetPrice function helps the user to find the price of flat based on the UIU

void GetPrice(struct PropertySale *head) {
    int UIU;
    printf("Enter UIU to retrieve the sales price of a flat:\n");
    scanf("%d", &UIU);

    //if there is no node
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }

    //if there are at least a nodes
    struct PropertySale* cn = head;
    while (cn != NULL) {
        if (cn->UIU == UIU) {
            printf("The sales price for the property with UIU %d is: %.2f\n", UIU, cn->price);
            return;
        }
        cn = cn->nextNode;
    }

    printf("Property with UIU %d is not found.\n", UIU);
}

// SalesCount Function show the total number of sold properties

void SalesCount(struct PropertySale *head) {
    //if there is no node
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }
    //if there are at least a node
    int count = 0;
    struct PropertySale* cn = head;
    while (cn != NULL) {
        count++;
        cn = cn->nextNode;
    }

    printf("Total number of sales: %d\n", count);
}

//AveragePrice function show the the total average price.

void AveragePrice(struct PropertySale *head) {
    //if there is no node
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }
    //if there are at least a node
    float totalPrice = 0.0;
    int count = 0;

    struct PropertySale* cn = head;

        while (cn != NULL) {
            totalPrice += cn->price;
            count++;
            cn = cn->nextNode;
        }


        if (count > 0) {

            float average = totalPrice / count;

                printf("Average price of all sales: %.2f\n", average);
        }

        else
            printf("No sales found.\n");
}

int main() {
    struct PropertySale* head = NULL;
    int choice, pos = 0;

    do {
        printf("1. Sales\n");
        printf("2. Erase\n");
        printf("3. Search\n");
        printf("4. PrintDB\n");
        printf("5. GetZIP\n");
        printf("6. GetPrice\n");
        printf("7. SalesCount\n");
        printf("8. AveragePrice\n");
        printf("9. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                Sales(&head);
                pos++;
                break;
            case 2:
                Erase(&head);
                break;
            case 3:
                Search(head);
                break;
            case 4:
                PrintDB(head);
                break;
            case 5:
                GetZIP(head);
                break;
            case 6:
                GetPrice(head);
                break;
            case 7:
                SalesCount(head);
                break;
            case 8:
                AveragePrice(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 9);

    return 0;
}

