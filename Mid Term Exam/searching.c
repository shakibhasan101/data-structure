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

int linear_search(int a[], int lb, int ub, int value)
{
    for(int i=lb;i<ub;i++)
    {
        if(a[i]==value)
            return i;

    }
    return -1;

}
int binary_search(int a[], int value)
{
    int beg=0, end=10;

    while (beg<=end)
    {
        int mid = (beg+end)/2;

        if(value==a[mid])
            return mid;
        else
        {
            if (value >a[mid]) beg =mid+1;
            else end =mid-1;
        }
    }
    return -1;
}


int main()
{

    int a[10] ={1,2,3,4,5,6,7,8,9,10};
    int idx = binary_search(a,7);



    if(idx==-1)
        printf("Value not found");
    else
    printf("Value found");
//    int a[100], lb=0, ub=20;
//    insert_array(a, lb, ub);
//    display(a, lb, ub);
//    int idx = linear_search(a, lb, ub, 91);
//    if (idx==-1)
//        printf("Value not found!");
//    else
//        printf("Value found at the position of %d",idx+1);


return 0;

}
