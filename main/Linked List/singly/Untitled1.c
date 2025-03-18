#include<stdio.h>

struct Node
{
    int value;
    struct Node *next;
};


struct Node *createNode (int value)
{
 struct Node *nn= (struct Node *)malloc (sizeof(struct Node));
 nn->value =value;
 nn->next =NULL;
 return nn;
}


void insert(struct Node **head, int value)
{
   struct Node *nn = createNode(value);


    if(*head==NULL)
        {*head = nn;
        return ;
        }

    nn->next =*head;
    *head =nn;

}


void delete(struct Node **head)
{
 if(*head==NULL)
        return ;
 struct Node *cn = *head;
 *head=cn->next;
 free(cn);

}


void traverse (struct Node *head)
{
    if(head==NULL)
        return ;
    struct Node *cn =head;
    while (cn!=NULL)
    {
        printf("%d ", cn->value);
        cn=cn->next;
    }
    printf("\n");

}


int main()
{


    struct Node *head = NULL;
    insert (&head, 56);
    insert (&head, 75);
    insert (&head, 45);
    traverse(head);
    delete(&head);
    traverse(head);


    return 0;
}
