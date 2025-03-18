#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int data)
{
    struct Node *nn = (struct Node*) malloc (sizeof(struct Node));
    nn->data =data;
    nn->next =NULL;
    return nn;

}

void insert(struct Node **head, int data)
{
    struct Node *nn=create(data);

    if (*head == NULL){

        *head=nn;
        return ;
    }

    struct Node *cn = *head;
    while (cn->next!=NULL)
    {
        cn=cn->next;
    }
    cn->next =nn;
}
void delete(struct Node **head)
{
    if(*head==NULL)
        return ;
    struct Node *cn = *head;

    if(cn->next ==NULL)
    {
        *head = cn->next;
        free(cn);
        return ;
    }

    struct Node *pn =NULL;
    while (cn->next!=NULL)
    {
        pn=cn;
        cn=cn->next;
    }
    pn->next =NULL;
    free(cn);
    return ;


}


void traverse (struct Node *head)
{
    if(head == NULL)
        return ;

    struct Node *cn = head;
    while (cn!= NULL)
    {
        printf("%d ",cn->data);
        cn= cn->next;
    }
    printf("\n");
}

int main()

{

    struct Node *head =NULL;
    insert(&head,76);
    insert(&head,45);
    insert(&head,87);
    insert(&head,96);
    traverse(head);
    delete(&head);
    delete(&head);
    traverse(head);

    return 0;
}
