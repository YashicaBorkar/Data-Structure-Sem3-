#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int stack[MAX];
int top=-1;

void display();

int isEmpty()
{
    if(top==-1)
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
    if(top==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    int x;
    printf("\nEnter value to be pushed : ");
    scanf("%d",&x);

    if(isFull()==1)
    {
        printf("\nStack is Full");
    }
    else 
    {
          top++;
          stack[top]=x;

    }

    display();
}

void pop()
{
    int x;

    if(isEmpty()==1)
    {
        printf("\nStack is Empty");
    }
    else
    {
       x=stack[top];
       printf("\nElement to be removed is %d",x);
       top--;
    }

    display();
}

void display()
{
    int x=top;

     printf("\nStack : ");

    while(x!=-1)
    {
        printf("\n%d",stack[x]);
        x--;
    }
}

int main()
{
     int ch=1,x;

    while(ch!=0)
    {
        printf("\nMENU \n1.Push \n2.Pop \n3,Display \n4.Exit \nEnter Choice : ");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
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