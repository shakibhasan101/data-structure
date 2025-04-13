#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5

int front =-1;
int rear= -1;

bool isFull()
{
    if((rear+1)%SIZE==front || rear == (front-1-SIZE)%SIZE) return true;
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
        rear = (rear+1)%SIZE;
    }
    Q[rear]=item;
}

void deQueue(int Q[])
{
    if(isEmpty()) return ;

    else if (front==rear)
        front=rear=-1;

    else
        front=(front+1)%SIZE;
}
void display(int Q[])
{
    if(isEmpty())
    {
         printf("The Queue is Empty!\n");
         return;
    }
    if (front <=rear)

    {
     for(int i=front ;i<=rear;i++)
     printf("%d ",Q[i]);
     printf("\n");

    }
    else
    {

        for (int i=front ; i<SIZE ; i++)
            printf("%d ",Q[i]);
        for (int i =0;i<=rear ; i++)
            printf("%d ",Q[i]);
            printf("\n");
    }

}


int main()
{
    int Queue[SIZE];
    enQueue (Queue, 23);
    enQueue (Queue, 35);
    enQueue (Queue, 43);
    enQueue (Queue, 94);
    enQueue (Queue, 23);
    display (Queue);
    deQueue (Queue);
    enQueue (Queue, 63);
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


