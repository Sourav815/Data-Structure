#include <stdio.h>
#include <math.h>
#define max 20
char postfix[50];
int stack[max];
int top = -1;

void push(int value);
int pop(void);

int main()
{
    int i, x, y, r;
    printf("Enter the postfix expression: ");
    gets(postfix);
    i = 0;
    while (postfix[i])
    {
        switch (postfix[i])
        {
        case '+':
        {
            y = pop();
            x = pop();
            push(x + y);
            break;
        }
        case '-':
        {
            y = pop();
            x = pop();
            push(x - y);
            break;
        }
        case '^':
        {
            y = pop();
            x = pop();

            push(pow(x, y));
            break;
        }
        case '*':
        {
            y = pop();
            x = pop();
            push(x * y);
            break;
        }
        case '/':
        {
            y = pop();
            x = pop();
            push(x / y);
            break;
        }

        default:
        {
            r = postfix[i] - '0';
            push(r);
            break;
        }
        }
        i++;
    }
    printf("The result is %d: ",stack[top]);
    return 0;
}

void push(int value)
{
    if (top == max - 1)
    {
        printf("Overflow");
        return;
    }
    else
    {
        stack[++top] = value;
    }
}
int pop(void)
{
    int data;
    if (top == -1)
    {
        printf("stack UnderFlow");
        return -1;
    }
    else
    {
        data = stack[top--];
        return data;
    }
}