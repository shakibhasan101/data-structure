#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 5

int rear =-1;

struct PQitem
{
    int priority_queue;
    int value;
};

bool isFull()
{
    if(rear==SIZE-1) return true;
    else return false;
}

bool isEmpty()
{
    if (rear ==-1)
        return true;
    else false;
}

void enQueue (struct PQitem Q[], int value, int p)
{
    if(isFull())

    {
        printf("Queue is FUll\n");
        return ;
    }

    rear +=1;
    Q[rear].value=value;
    Q[rear].priority_queue=p;

}

int getHP(struct PQitem Q[])
{
    int max = Q[0].priority_queue;

    for (int i=1; i<=rear; i++ )
        if(Q[i].priority_queue>max)
            max=Q[i].priority_queue;

    return max;

}

void deQueue(struct PQitem Q[])

{
    if (isEmpty())
    {
        printf("Emptyr");
        return ;
    }
    int  p = getHP(Q);
    int i ;

    for (i=0; i<=rear; i++)
    {
        if(p==Q[i].priority_queue)
        {
            break;
        }

    }
    for(int j=i; j<=rear; j++)
    {
        Q[j].value= Q[j+1].value;
        Q[j].priority_queue= Q[j+1].priority_queue;

    }
    rear -=1;



}


void display (struct PQitem PQ[]) {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }

    for (int i = 0; i <= rear; i++)
        printf ("(%d, %d) ", PQ[i].value, PQ[i].priority_queue);
    printf ("\n");
}




int main () {
    struct PQitem PQ[SIZE];
    enQueue (PQ, 23, 2);
    enQueue (PQ, 42, 3);
    enQueue (PQ, 13, 1);
    enQueue (PQ, 6, 2);
    enQueue (PQ, 9, 1);
    display (PQ);
    deQueue (PQ);
    display (PQ);
    deQueue (PQ);
    display (PQ);
    deQueue (PQ);
    display (PQ);
    deQueue (PQ);
    display (PQ);
    return 0;
}

