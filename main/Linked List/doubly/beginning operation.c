#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *create(int value)
{
 struct Node *nn = (struct Node *) malloc (sizeof(struct Node));

 nn->next = NULL;
 nn->value =value;
 nn->prev = NULL;

 return nn;
}

void insertNode(struct Node **head, struct Node **tail, int value)
{
    struct Node *nn = create(value);

    if(*head ==NULL)
    {
        *head=*tail=nn;
        return ;
    }

    struct Node *cn = *head;
    cn->prev = nn;
    nn->next =cn;
    *head =nn;


}

void deleteNode (struct Node **head, struct Node **tail)
{
    if(*head==NULL)
        return ;

    struct Node *cn = *head;
    if(*head==*tail)
    {
        *head=*tail=NULL;
        return;
    }

    (cn->next)->prev =NULL;
    *head= cn->next;


}

void traverseForward(struct Node *head)
{
    if(head==NULL)
        return ;
    struct Node *cn = head;

    while (cn!=NULL)
    {
        printf("%d ",cn->value);
        cn=cn->next;
    }
    printf("\n");
}
void traverseBackward(struct Node *tail)
{
    if(tail==NULL)
        return ;
    struct Node *cn = tail;

    while (cn!=NULL)
    {
        printf("%d ",cn->value);
        cn=cn->prev;
    }
    printf("\n");
}
int main()
{
    struct Node *head=NULL;
    struct Node *tail=NULL;
    insertNode(&head,&tail,  45);
    insertNode(&head,&tail, 58);
    insertNode(&head,&tail , 73);
    traverseForward(head);
    traverseBackward(tail);
    deleteNode(&head,&tail);
    traverseForward(head);
    traverseBackward(tail);
}
