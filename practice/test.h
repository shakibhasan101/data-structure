#define SIZE 100
#define name printf("My name is Shakib Hasan");

void print_array(int a[] , int lb, int ub)
{
    int i;
    for (i=0;i<ub;i++)
        printf("%d ",a[i]);
    printf("\n");
}
 void swapping(int a[], int n1, int n2)
{
    int temp;

    temp= a[n1];
    a[n1]=a[n2];
    a[n2]=temp;

}

