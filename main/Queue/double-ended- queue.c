#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 #define SIZE 5

 int front =-1;
 int rear =-1;

 bool isFull ()
 {
     if((rear+1)%SIZE == front) return true ;
     else return false;
 }

 bool isEmpty()
 {
     if (front ==-1) return true;
     else return false;
 }

 void enQueuefront(int Q[], int item)
 {

      if(isFull())
     {
         printf("The queue is full!\n");
         return ;
     }
     else if (isEmpty())
     front=rear=0;

     else
        front = (front-1+SIZE)%SIZE;
     Q[front]=item;
 }
 void enQueuerear(int Q[], int item)
 {
      if(isFull())
     {
         printf("The queue is full!\n");
         return ;
     }
     else if (isEmpty())
     front=rear=0;

     else
        rear = (rear+1)%SIZE;
     Q[rear]=item;

 }

 void deQueue(int Q[])
 {
     if(isEmpty())
     {
         printf("Queue is empty!\n");
         return;
     }
     else
     {
         front= (front+1)%SIZE;
     }
 }

 void display (int Q[])
 {

     if(isEmpty())
     {
         printf("The Queue is Empty!\n");

     }

     if (front <=rear )
     {
         for (int i=front ;i<=rear;i++)
         printf("%d ",Q[i]);
         printf("\n");

     }

     else
     {

         for(int i=front;i<SIZE;i++)
            printf("%d ",Q[i]);
         for (int i=0;i<=rear;i++)
            printf("%d ",Q[i]);
         printf("\n");

     }
 }

 int main()
 {

     int queue[SIZE];

     enQueuefront(queue, 65);
     enQueuefront(queue, 55);
     enQueuefront(queue, 34);
     display(queue);
     enQueuerear(queue, 44);
     enQueuerear(queue, 98);
     display(queue);
     deQueue(queue);
     deQueue(queue);
     display(queue);

 }
