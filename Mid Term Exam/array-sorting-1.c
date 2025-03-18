#include<stdio.h>

void insert_array(int a[], int lb, int ub)
{
    for(int i=lb;i<ub;i++)
    {
        a[i]=rand()%100;

    }

}

void display(int a[], int lb, int ub)
{
    for (int i=lb;i<ub;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swapping(int a[], int x, int y)
{
    int temp;
    temp =a[x];
    a[x] =a[y];
    a[y]=temp;

}


void bubble_sort(int a[], int lb, int ub)
{

    for(int j=lb;j<ub-1;j++)
        for(int i=lb;i<ub-j-1;i++)
            if(a[i]>a[i+1])
            swapping(a, i, i+1);

}

void selection_sort(int a[], int lb, int ub)
{
    for (int i=lb;i<ub-1;i++)
    {
        int smallest=i;
        for(int j=i+1;j<ub;j++)
        {
            if(a[smallest]>a[j])
            smallest=j;

        }
        swapping(a, smallest, i);
    }

}

void insertion_sort(int a[], int lb, int ub)
{

    for (int i=lb+1;i<ub;i++)
    {
        int curr= a[i];
        int prev= i-1;

        while (prev>=lb && a[prev]>curr)
        {
            a[prev+1]=a[prev];
            prev--;
        }

        a[prev+1]=curr;
    }

}

int main()
{
    int a[100], lb=0, ub=10;
insert_array(a, lb, ub);
display(a, lb, ub);
//bubble_sort(a, lb, ub);
//display(a, lb, ub);
//selection_sort(a, lb, ub);
//display(a, lb, ub);

insertion_sort(a, lb, ub);
display(a,lb, ub);
    return 0;
}
