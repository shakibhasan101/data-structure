#include<stdio.h>
#include<stdlib.h>

void insert_data(int a[], int lb, int ub)
{
    for (int i=lb; i<ub;i++)
    {
        a[i]=rand()%20;
    }
}

void display(int a[], int lb, int ub)
{

    for (int i=lb; i<ub;i++)
        printf("%d ",a[i]);
    printf("\n");
}


void counting_sort(int a[], int lb , int ub)
{
    int max=0;
    for (int i=lb;i<ub;i++)
        if(max<a[i])
            max=a[i];
    int c[max+1];

    for (int i=lb;i<=max;i++)
        c[i]=0;
    for (int i=lb; i<ub;i++)
        c[a[i]]+=1;
    for (int i=1;i<=max;i++)
        c[i]+=c[i-1];


        int b[ub+1];
    for (int i=ub-1; i>=lb; i--)
    {
        b[c[a[i]]-1] = a[i];
        c[a[i]]-=1;
    }

    for (int i=lb; i<ub;i++)
    a[i]= b[i];


}
int main()
{
    int a[100], lb=0, ub=10;

    insert_data(a, lb, ub);
    display (a, lb, ub);
    counting_sort(a, lb, ub);
    display (a, lb, ub);


    return 0;
}
