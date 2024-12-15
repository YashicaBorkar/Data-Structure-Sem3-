#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct Queue
{
    struct node* front;
    struct node* rear;
}Q;

void display(Q *q);

void enqueue(Q *q)
{
    int x;
    printf("\nEnter Data : ");
    scanf("%d",&x);

    node *nn,*p;

    nn=(node*)malloc(sizeof(node));
    nn->data=x;
    nn->next=NULL;

    if(q->front==NULL&&q->rear==NULL)
    {
        q->front=q->rear=nn;
    }
    else
    {
        p=q->rear;

        p->next=nn;
        q->rear=nn;
        
    }

    display(q);
}

void dequeue(Q *q)
{
    node *p,*r;

    if(q->front==q->rear)
    {
        p=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(p);
    }
    else
    {
        p=q->front;
        q->front=p->next;
        free(p);
    }


    display(q);
}

void display(Q *q)
{
    node *p;

    p=q->front;
    
    printf("\nQueue : ");

    if(q->front==NULL&&q->rear==NULL)
    {
        printf("\nQueue is Empty");
        
    }
    else
    {
    while(p!=NULL)
    {
        printf("\t%d",p->data);
        p=p->next;
    }
    }
}

int main()
{
    int ch=1,x;

    Q q;
    q.front=q.rear=NULL;

    while(ch!=0)
    {
        printf("\nMENU \n1.Enqueue \n2.Dequeue \n3,Display \n4.Exit \nEnter Choice : ");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            enqueue(&q);
            break;

            case 2:
            dequeue(&q);
            break;

            case 3:
            display(&q);
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
