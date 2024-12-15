#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct LL
{
    struct node* start;
}LL;

void display(LL *l);

void push(LL *l)
{
    int x;
    printf("\nEnter value to be pushed : ");
    scanf("%d",&x);

    node *nn,*p;
    nn=(node*)malloc(sizeof(node));
    nn->data=x;
    nn->next=NULL;



    if(l->start==NULL)
    {
        l->start=nn;
    }
    else
    {
        
        nn->next=l->start;
        l->start=nn;
    }

    display(l);
}

void pop(LL *l)
{
    node *p,*q;

    if(l->start==NULL)
    {
        printf("\nList is empty");
    }
    else if(l->start->next==NULL)
    {
        p=l->start;
        l->start=NULL;

        free(p);
    }
    else
    {
        p=l->start;
        l->start=p->next;

        free(p);
    }

    display(l);
}

void display(LL *l)
{
    node *p;
    
    p=l->start;

    printf("\nStack : ");

    while(p!=NULL)
    {
        printf("\n%d",p->data);
        p=p->next;
    }
}

int main()
{
     int ch=1,x;

     LL l;
     l.start=NULL;

    while(ch!=0)
    {
        printf("\nMENU \n1.Push \n2.Pop \n3,Display \n4.Exit \nEnter Choice : ");
        scanf("%d",&x);

        switch(x)
        {
            case 1:

            push(&l);
            break;

            case 2:
            pop(&l);
            break;

            case 3:
            display(&l);
            break;

            case 4:
            exit(0);
            break;

            default :
            printf("\n Wrongg choice");
            break;

        }

        printf("\nDo you wish to continue (1/0) : ");
        scanf("%d",&ch);
    }

    return 0;
}