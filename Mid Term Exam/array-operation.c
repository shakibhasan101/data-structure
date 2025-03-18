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

void insert_data(int a[], int lb, int ub, int value, int position)
{

     for (int i=ub;i>=position-1; i--)
    a[i+1]=a[i];

    a[position-1]=value;

}
void delete_data_by_postion(int a[], int lb, int ub, int position)
{
    int idx=position-1;
    for(int i=idx;i<ub;i++)
    {
        a[i]=a[i+1];

    }
}
void delete_data_by_value (int a[],int lb, int ub, int value)
{
int idx= search_data(a,lb, ub, value);

if(idx!=-1)
{
    for(int i=idx;i<ub;i++)
    a[i]=a[i+1];
}
else
printf("Value not found to delete\n");

}

int search_data(int a[], int lb, int ub, int value)
{
    int i;
    for (i=lb;i<ub;i++)
    {
        if(a[i]==value)
            return i;
    }
    return -1;

}

void update (int a[], int lb, int ub, int pv, int nv)
{
    int idx=search_data(a,lb, ub,pv);
    a[idx]=nv;

}


int main()
{
    int a[100], lb=0, ub=10;
   insert_array(a,lb,ub);
   display(a,lb,ub);
   insert_data(a,lb,ub,76,4);
    display(a,lb,ub);
    delete_data_by_postion(a,lb,ub,4);
    display(a,lb,ub);

    int search = search_data(a, lb,ub, 41);

    if(search==-1)
        printf("Value not found\n");
    else
        printf("Value found at the position %d\n",search+1);

    display(a,lb,ub);

    delete_data_by_value(a, lb, ub, 50);
    display(a,lb,ub);
    update(a, lb, ub,0,99);
    display(a,lb,ub);

    return 0;
}
