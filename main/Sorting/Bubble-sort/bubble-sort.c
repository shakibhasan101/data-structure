#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void insert(int a[], int lb, int ub)
{
    for (int i=lb; i<ub;i++)
    {
        a[i]=rand()%100;
    }
}
void display (int a [], int lb, int ub)
{
    for (int i=lb; i<ub;i++)
        printf("%d ", a[i]);
        printf("\n");

}
void swap (int a[], int n1, int n2)
{
    int temp;
    temp =a[n1];
    a[n1]=a[n2];
    a[n2]=temp;

}

void bubble_sort(int a[], int lb, int ub)
{
int i, j;

for (j=lb; j<ub; j++)
{
    for (i=lb; i<ub-j-1; i++)
    {
        if(a[i]>a[i+1])
        {
            swap(a, i, i+1);
        }
    }

}


}
int main()
{
 int a[SIZE], lb=0, ub=30;
 insert(a, lb, ub);
 display(a, lb, ub);
 bubble_sort(a, lb, ub);
 display(a, lb, ub);


 return 0;
}
