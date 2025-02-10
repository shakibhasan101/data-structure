#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int a[SIZE]; lb=0; ub=20;
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

void insertion_sort(int a[], int lb, int ub)
{

    for (int i=lb; i<ub-1;i++)
    {
       int current =a[i+1];
       int previous =i;

       while (previous>=0 && current<a[previous] )
       {
           a[previous+1] =a[previous];
           previous -=1;
       }

       a[previous+1]=current;

    }

}
int main()
{
    insert_data(a, lb, ub);
    display( a, lb, ub);
    insertion_sort(a, lb, ub);
    display( a, lb, ub);


    return 0;
}

