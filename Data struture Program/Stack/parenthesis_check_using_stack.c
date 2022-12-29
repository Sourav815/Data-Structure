#include <stdio.h>
#include <string.h>
#define max 20

char expression[max];
char stack[max];
int top = -1;

void push(char stack[], char value);
char pop(char stack[]);
char peek(char stack[]);

int main(void)
{
    int flag = 0;
    char temp;

    printf("Enter the expression: ");
    gets(expression);
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(stack, expression[i]);
        }
        else if (expression[i] == ')' && peek(stack) == '(')
        {
            flag = 1;
            temp = pop(stack);
        }
        else if (expression[i] == '}' && peek(stack) == '{')
        {
            flag = 1;
            temp = pop(stack);
        }
        else if (expression[i] == ']' && peek(stack) == '[')
        {
            flag = 1;
            temp = pop(stack);
        }
    }
    if (flag == 1 && top == -1)
    {
        printf("Valid Expression");
    }
    else if (flag == 0 && top == -1)
    {
        printf("Valid Expression");
    }
    else
    {
        printf("InValid Expression");
    }
    return 0;
}

void push(char stack[], char value)
{
    if (top >= max - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
    }
}
char pop(char stack[])
{
    char ch;
    if (top == -1)
        return 'a';
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}
char peek(char stack[])
{
    if (top == -1)
        return 'a';
    else
    {
        return stack[top];
    }
}
