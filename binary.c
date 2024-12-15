#include<stdio.h>
#include<stdlib.h>

typedef struct node
{

    int data;
    struct node* left,*right;

}node;

node *get_node()
{
    node *nn;

    nn=(node*)malloc(sizeof(node));
    nn->left=NULL;
    nn->right=NULL;
    
    return nn;
}

void insert(node *root,node *nn)
{
char ch,n;
    printf("\nWhere to insert left or right (l/r)");
    scanf("%c",&n);
    scanf("%c",&ch);

    if(ch=='l')
    {
        if(root->left==NULL)
        {
            root->left=nn;
        }
        else
        {
            insert(root->left,nn);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=nn;
        }
        else
        {
            insert(root->right,nn);
        }
    }
}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
    inorder(temp->left);
    printf("\t%d",temp->data);
    inorder(temp->right);
    }
}

void preorder(node *temp)
{
    if(temp!=NULL)
    {
    printf("\t%d",temp->data);
    preorder(temp->left);
    preorder(temp->right);
    }
}

void postorder(node *temp)
{
    if(temp!=NULL)
    {
    postorder(temp->left);
    postorder(temp->right);
    printf("\t%d",temp->data);
    }
}

int main()
{
    int ch=1,choice,x=1,y;

    node *root,*nn;
    root=NULL;

    do
    {
       printf("\nMenu \n1.Insert \n2.Inorder \n3.Preorder \n4.Postorder \n5.exit \nEnter Choice : " );
       scanf("%d",&choice);

       switch(choice)
       {
         case 1:
         do
         {
            nn=get_node();
            printf("\nEnter data : ");
            scanf("%d",&y);
            nn->data=x;

            if(root==NULL)
            {
                root=nn;
            }
            else
            {
                insert(root,nn);
            }

            printf("\nDo you wan to continue to insert (1/0) : ");
            scanf("%d",&x);

         }while(x==1);
         
         
       }

       printf("\nDo you wan to continue (1/0) : ");
            scanf("%d",&ch);

    }while(ch!=0);
    
    return 0;
}
