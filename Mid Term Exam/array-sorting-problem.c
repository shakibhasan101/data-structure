#include<stdio.h>

void display(int a[],int size)
{

    printf("%d\n",sizeof(a)/4);
for(int i=0;i<size;i++)
    printf("%d ",a[i]);
printf("\n");
}


int main()
{
    int a[10]={3,2,5,6,1,9,8,4,10,7};
        printf("%d\n",sizeof(a)/4);


    display(a,sizeof(a)/4);

    return 0;
}
