#include<stdio.h>
#define SIZE 5
int top =0;

void push (int stack[], int value )
{

    if(top==SIZE)

       {
        printf("Overflow!");
    return ;
       }

    stack[top]=value;
    top+=1;
}

int pop (int stack[])
{
    if(top==0)
    {
        printf("Underflow");
        exit(1);
    }


}

int main()
{

    int stack [SIZE];
    return 0;
}
