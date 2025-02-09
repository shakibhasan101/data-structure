#include "test.h"

void bubble(int a [], int lb, int ub)
{
    int i, j;
    for (j=0;j<ub-1;j++)
    for (i=0;i<ub-1;i++)
    {
        if (a[i]>a[i+1])
            swapping(a, i, i+1);
    }
}

int main()
{
    int a[SIZE]={33,56, 39, 65, 87, 76, 95, 21, 19, 83};
    int lb=0, ub=10;

    print_array(a, lb, ub);
    bubble( a, lb, ub);
    print_array(a, lb, ub);



}
