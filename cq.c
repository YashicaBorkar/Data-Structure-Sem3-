#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>

#define MAX 20

void display();

int q[MAX];
int f=-1;
int r=-1;

int isEmpty()
{
    if(f==-1&&r==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(f==((f+1)%MAX))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    int x;
    printf("\nEnter a number to be enqueued : ");
    scanf("%d",&x);

    if(isEmpty()==1)
    {
        f=0;
        r=0;
        q[r]=x;
    }
    else if(isFull()==1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        r=(r+1)%MAX;
        q[r]=x;
    }

   display();

}

void dequeue()
{
    int x;

    if(isEmpty()==1)
    {
        printf("\nQueue is Empty");
    }
    else if(f==r)
    {
       x=q[f];
        printf("\n Element to be dequeued is %d ",x);
        f=-1;
        r=-1;
    }
    else
    {
        x=q[f];
        printf("\n Element to be dequeued is %d ",x);
        
        f=(f+1)%MAX;
    }
    
    display();
}

void display()
{
    printf("\n Queue : ");
    for(int i=f;i<=r;i++)
    {
        printf("\t%d",q[i]);
    }
}

int main()
{
    int ch=1,x;

    while(ch!=0)
    {
        printf("\nMENU \n1.Enqueue \n2.Dequeue \n3,Display \n4.Exit \nEnter Choice : ");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
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