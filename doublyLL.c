#include<stdio.h>
#include<stdlib.h>

typedef struct node
{

    int data;
    struct node *next,*prev;

}node;

typedef struct LL
{
    struct node *start;
}LL;

void display(LL *l);

void insertbegin(LL *l)
{
    int x;
    printf("\nEnter Data : ");
    scanf("%d",&x);

    node *nn,*p;

    nn=(node*)malloc(sizeof(node));
    nn->data=x;
    nn->next=NULL;
    nn->prev=NULL;

    if(l->start==NULL)
    {
        l->start=nn;
    }
    else
    {
       // p=l->start;

        nn->next=l->start;
        l->start->prev=nn;
        l->start=nn;
        
    }

    display(l);
}


void insertend(LL *l)
{
    int x;
    printf("\nEnter Data : ");
    scanf("%d",&x);

    node *nn,*p;

    nn=(node*)malloc(sizeof(node));
    nn->data=x;
    nn->next=NULL;
    nn->prev=NULL;

    if(l->start==NULL)
    {
        l->start=nn;
    }
    else
    {
        p=l->start;

        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=nn;
        nn->prev=p;
        
    }

    display(l);
}

void deletebegin(LL *l)
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
        q=p->next;

        q->prev=NULL;
        l->start=q;

        free(p);
      
    }

    display(l);
}

void deleteend(LL *l)
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
        q=l->start;
       
       while(q->next->next!=NULL)
       {
         q=q->next;
       }

       p=q->next;
       q->next=NULL;

       free(p);
      
    }

    display(l);
}

void display(LL *l)
{
    node *p;
    
    p=l->start;

    printf("\nQueue : ");

    while(p!=NULL)
    {
        printf("\t%d",p->data);
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
        printf("\nMENU \n1.Insertbegin \n2.Insertend \n3.Deletbegin \n4.DeleteEnd \n5.Display \n6.Exit \nEnter Choice : ");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            insertbegin(&l);
            break;

            case 2:
            insertend(&l);
            break;
            
            case 3:
            deletebegin(&l);
            break;
            
            case 4:
            deleteend(&l);
            break;

            case 5:
            display(&l);
            break;

            case 6:
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

