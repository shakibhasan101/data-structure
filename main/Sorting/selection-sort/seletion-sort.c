#include<stdio.h>
#include<stdlib.h>
#include "utility.h"
#define SIZE 100
int a[SIZE]; lb=0; ub=10;
void insert_data(int a[], int lb, int ub)
{
    for (int i=lb; i<ub;i+=1)
    {
        a[i]=rand()%100;
    }
}
void display(int a[], int lb, int ub)
{
    for (int i =lb; i<ub; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void swapping (int a[], int n1, int n2)
{
    int temp;
    temp =a[n1];
    a[n1]=a[n2];
    a[n2]=temp;

}

void selection_sort(int a[], int lb, int ub)
{
    int i,j;
    for (i=lb;i<ub-1;i++)
    {

        int  idx=i;
        for ( j=i+1;j<ub;j++)
        {
            if(a[idx]>a[j])
                idx=j;
        }
        swapping(a, idx, i);
    }


}

int main()
{
    insert_data(a, lb, ub);
    display( a, lb, ub);
    selection_sort(a, lb, ub);
    display( a, lb, ub);




    return 0;
}
