#include "test.h";

void insertion(int a[], int lb, int ub, int p, int num)
{
    int i,j;
    for (i=ub;i>=p-1;i--)
        {

        a[i+1]=a[i];
        }
    a[p-1]=num;
    for (i=0;i<ub;i++)
        printf("%d ",a[i]);
        printf("\n");

}

void delation(int a[], int lb, int ub, int p )
{
    int i;
    for (i=p-1;i<ub;i++)
    {
        a[i]=a[i+1];
    }
    for (i=0;i<ub;i++)
        printf("%d ",a[i]);
        printf("\n");
}
int search_array(int a[],int lb, int ub,int s)
{
    int i;
    for (i=lb;i<ub;i++)
        if(s==a[i]) return i;
    return -1;

}
void update(int a[], int lb, int ub, int p,  int value)
{
    a[p]=value;
}

int main()
{
int lb=0, ub=10;
int a[SIZE]={23,44,26,83,97,23,43,76,29,38};
print_array(a , lb, ub);
insertion(a, lb,ub, 3, 76);
print_array(a , lb, ub);
delation ( a , lb, ub, 5);
print_array(a , lb, ub);
int s = search_array(a, lb,ub,97);
if (s==-1)
    printf("Data not found\n");
else
    printf("Data found in the position of %d\n",s+1);

update(a, lb, ub, s, 54);
print_array(a , lb, ub);

    return 0;
}
