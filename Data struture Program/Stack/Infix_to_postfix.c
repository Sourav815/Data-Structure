#include <stdio.h>
#include <string.h>
#define max 50

// Global variable declaration
char stack[max];
char inFix[max];
char postFix[50];
int top = -1;

// function declaration
void push(char stack[], char pushedData);
char pop(char stack[]);
char peek(char stack[]);
int getPriority(char);

int main()
{
    int j;
    char temp;
    printf("Enter the Expression { example: (a+b*c) }: ");
    gets(inFix);
    j = 0;
    for (int i = 0; i < strlen(inFix); i++)
    {
        if ((inFix[i] >= 65 && inFix[i] <= 90) || (inFix[i] >= 97 && inFix[i] <= 122))
        {
            postFix[j] = inFix[i];
            j++;
        }

        else if (inFix[i] == '(')
            push(stack, inFix[i]);
        else if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/' || inFix[i] == '$')
        {
            while ((top != -1) && (peek(stack) != '(') && (getPriority(inFix[i]) < getPriority(peek(stack))))
            {
                postFix[j] = pop(stack);
                j++;
            }
            push(stack, inFix[i]);
        }
        else if (inFix[i] == ')')
        {
            while (peek(stack) != '(')
            {
                postFix[j] = pop(stack);
                j++;
            }
            pop(stack);
        }
    }
  printf("InFix to PostFix Expression: ");
  puts(postFix);
    return 0;
}

void push(char stack[], char pushedData)
{
    if (top == (max - 1))
        printf("Stack overflow");
    else
    {
        top++;
        stack[top] = pushedData;
    }
}

char pop(char stack[])
{
    char data;
    if (top == -1)
        printf("stack underflow\n");
    else
    {
        data = stack[top];
        top--;
    }
    return data;
}

char peek(char stack[])
{
    if (top == -1)
        printf("stack underflow from peek");
    else
        return stack[top];
}

int getPriority(char operator)
{
    if (operator== '$')
        return 3;
    else if (operator== '/' || operator== '*')
        return 2;
    else if (operator== '+' || operator== '-')
        return 1;
}