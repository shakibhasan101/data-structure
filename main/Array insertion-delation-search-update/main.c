#include "utility.h"
int ub=10, lb=0, a[SIZE];

void insertion(int a [], int lb, int ub, int position, int value)
{
int i, idx;
idx= position -1;

    for (i=ub ;i>=idx;i--)
    {
        a[i+1]=a[i];
    }
    a[idx]=value;
}

void delation (int a [], int lb, int ub, int position)
{
    int index, i;
    index=position -1;
    for (i=index; i<=ub;i++)
        {
            a[i]=a[i+1];
        }
}
int searching(int a[], int lb, int ub, int value)
{
    int i;
    for (i=lb;i<ub; i++)
    {
        if (a[i]==value)
            return i;
    }

    return -1;

}

void update(int a [], int lb, int ub, int privious_value, int new_value)
{
    int index;
    index = searching(a,lb, ub, privious_value);
    a[index]=new_value;
}


int main()
{
display_data(a, lb, ub);
insert_data(a, lb, ub);
display_data(a, lb, ub);
insertion(a, lb, ub, 3, 98);
display_data(a, lb, ub+1);
delation(a, lb, ub, 3);
display_data(a, lb, ub);
int s = searching(a, lb, ub,24);
display_search(s);
display_data(a, lb, ub);
update(a, lb, ub, 62, 64);
display_data(a, lb, ub);
update(a, lb, ub, 64, 0);
display_data(a, lb, ub);






    return 0;
}
