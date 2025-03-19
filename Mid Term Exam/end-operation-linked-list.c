
#include<stdio.h>
#include<stdlib.h>

struct Node {
int value ;
struct Node *next;
};

struct Node *create(int value)
{
 struct Node *nn= (struct Node *) malloc (sizeof(struct Node));
 nn->value=value;
 nn->next = NULL;
 return nn;
}
void insertNode(struct Node **head, int value)
{
    struct Node *nn =create(value);

    if(*head==NULL)
    {
        *head=nn;
        return;
    }

    struct Node *cn =*head;

    while (cn->next!=NULL)
    {
      cn=cn->next;
    }
    cn->next =nn;

}

void deleteNode(struct Node **head)
{
    if(*head==NULL)
        return ;

    struct Node *cn =*head;

    if(cn->next==NULL)
    {
     *head = cn->next;
     free(cn);
     return;
    }
    struct Node *pn=NULL;

    while (cn->next !=NULL)
    {
        pn=cn;
        cn=cn->next;
    }
    pn->next = NULL;
    free(cn);
    return;

}

void traverse(struct Node *head)
{
    if(head==NULL)
        return ;
    struct Node *cn=head;

    while (cn!=NULL)
    {
        printf("%d ", cn->value);
        cn=cn->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head=NULL;
    insertNode(&head, 45);
    insertNode(&head, 58);
    insertNode(&head, 73);
    traverse(head);
    deleteNode(&head);
    traverse(head);
    return 0;
}
