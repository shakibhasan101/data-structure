#include<stdio.h>

void pointer(int *ptr)
{
    //prt=&a;
    *ptr= 100;

}
void double_pointer (int **ptr)
{
    //ptr = &first;
    //*ptr=&a;
    //**ptr=a;
    **ptr = 200;
    printf("Output of Double ptr:\n");
printf("&ptr=%d,\tptr=%d\t *ptr=%d\t**ptr=%d\n",&ptr, ptr, *ptr, **ptr);



}
void triple_pointer(int ***ptr)
{

}
int main()
{
    int *first;
    int a=10;
    first = &a;
    int **second;
    second=&first;
    int ***third;
    third= &second;
printf("&a=%d,\ta=%d\n",&a, a);
printf("&first=%d,\tfirst=%d\t *first=%d\n",&first, first, *first);
printf("&second=%d,\tsecond=%d\t*second=%d\t**second=%d\n",&second, second, *second,**second);
printf("&third=%d,\tthird=%d\t*third=%d\t**third=%d\t***third=%d\n",&third, third, *third,**third, ***third);

pointer(&a);
printf("Output: a= %d\n",a);
double_pointer(&first);
printf("Output: a= %d\n",a);


    return 0;
}
