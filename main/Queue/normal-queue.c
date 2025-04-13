#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5
int front =-1;
int rear= -1;

bool isFull()
{
    if(rear==SIZE-1) return true;
    else return false;
}
bool isEmpty()
{
    if (front==-1) return true;
    else return false;
}

void enQueue ( int Q[], int item)
{
    if (isFull())
        {
        printf("Queue is full!\n");
        return;
        }
    else if(isEmpty())
        front=rear=0;

    else
    {
        rear+=1;
    }
    Q[rear]=item;

}
void deQueue(int Q[])
{
    if(isEmpty()) return ;
    else if (front<=rear)
        front+=1;

    else
        front=rear=-1;
}
void display(int Q[])
{
    if(isEmpty())
    {
         printf("The Queue is Empty!\n");
         return;
    }
    for (int i=front;i<=rear;i++)
        printf("%d ",Q[i]);
    printf("\n");


}


int main()
{
    int Queue[SIZE];
    enQueue (Queue, 23);
    enQueue (Queue, 35);
    enQueue (Queue, 43);
    enQueue (Queue, 94);
    display (Queue);
    deQueue (Queue);
    display (Queue);
    deQueue (Queue);
    display (Queue);
    deQueue (Queue);
    display (Queue);
    deQueue (Queue);
    display (Queue);
    deQueue (Queue);
    return 0;
}


