#include<stdio.h>

insert ()
{
    int dob, cl;
    printf("Enter you dob:");
    scanf("%d",&dob);
     printf("Enter you class:");
    scanf("%d",&cl);

}
int main()
{

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: insert ();
    }
}
