#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[20];
int top=-1;

void push(char x)
{
   stack[++top]=x;
}

char pop()
{
    char x=stack[top--];
    return x;
}

int priority(char x)
{
    switch(x)
    {
        case '(':
        return 1;
        break;

        case '+':
        case'-':
        return 2;
        break;

        case '*':
        case'/':
        return 3;
        break;

    }
}

int main()
{
    char infix[20],postfix[20],ch;

    int i=0,k=0;

    scanf("%s",infix);
    
    push('#');

    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
            }
            
            pop();
        }
        else if(isalnum(ch)==1)
        {
            postfix[k++]=ch;
        }
        else 
        {

                while(priority(stack[top])>=priority(ch))
                {
                    postfix[k++]=pop();
                }
                
                push(ch);
        }
    }

    while(stack[top]!='#')
    {
         postfix[k++]=pop();
    }

   postfix[k]='\0';

   printf("\npostfix expression : %s ",postfix);
//   while(postfix[i]!='\0')
//   {
//     printf("%c",postfix[i]);
//     i++;
//   }

}


/*
Incorrect scanf format for input:
In your current code, scanf("%c", infix) is wrong because %c reads a single character, but infix is a character array (string). To read a string, you should use %s.
Fix: Change scanf("%c", infix) to scanf("%s", infix).
2. Unclosed parentheses when popping:
After encountering a ')', the code pops until it finds '(', but you're not discarding the '(' from the stack.
Fix: Add pop(); after the while(stack[top] != '(') loop to discard the '('.
3. Incorrect priority comparison:
The condition while(priority(stack[top]) > priority(ch)) only checks for higher priority operators. You should also check for equal precedence to correctly handle left-to-right associativity.
Fix: Change while(priority(stack[top]) > priority(ch)) to while(priority(stack[top]) >= priority(ch)).
4. Error in printing the postfix expression:
You're trying to print postfix using printf("\npostfix expression : ", postfix);, but you're not passing the format specifier (%s) needed for a string.
Fix: Change the print statement to printf("\npostfix expression: %s", postfix);.
5. Postfix string termination:
The termination of the postfix array is incorrect. You're using postfix[++k] = '\0';, which leaves an empty spot before the termination character.
Fix: Use postfix[k] = '\0'; instead of postfix[++k] = '\0';.

Changed scanf("%c", infix) to scanf("%s", infix) to properly read the infix expression.
Added pop(); after the parentheses handling to discard '('.
Updated the condition to handle operators of equal precedence with while(priority(stack[top]) >= priority(ch)).
Fixed the print statement to correctly output the postfix expression using printf("\nPostfix expression: %s", postfix);.
Fixed the termination of the postfix string by using postfix[k] = '\0';.
This corrected code should now


*/