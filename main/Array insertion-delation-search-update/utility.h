#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void insert_data(int a[], int lb, int ub)
{
for (int i=lb;i<ub;i++)
{
a[i]=rand()%100;
}

}

void display_data(int a[], int lb, int ub)
{
    for (int i=lb; i<ub;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void traverse (int a[], int arr_size)
{
    int i;
    for (i=0; i<arr_size; i++ )
    {
        printf("%d ", a[i]);
    }
}

void display_search(int s)
{
    if (s==-1)
    printf("Value not found\n");
    else
    printf("Value found at the position of %d \n",s+1);


}
