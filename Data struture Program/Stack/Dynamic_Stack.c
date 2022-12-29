#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct st
{
    int data;
    struct st *link;
} stack;
stack *top = NULL;
stack *start = NULL;

void insertion(int val);
int deletion(void);
void display(void);

int main()
{
    int choice, val, result;
    do
    {
        printf("*********MENU******\n");
        printf("Press 1: Push Data\n");
        printf("Press 2: Pop Data\n");
        printf("Press 3: Display Data\n");
        printf("Press 0: Exit\n");
        printf("--------------------\n\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the data to store: ");
            scanf("%d", &val);
            printf("\n\n");
            insertion(val);
            break;
        }
        case 2:
        {
            result = deletion();
            if (result != -1)
            {
                printf("Deleted element is %d\n\n", result);
            }
            break;
        }
        case 3:
        {
            display();
            break;
        }

        default:
            printf("Have a nice day\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
void insertion(int val)
{
    stack *newnode;
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = val;
    if (top == NULL)
    {
        newnode->link = NULL;
        top = start = newnode;
    }
    else
    {
        newnode->link = top;
        top = newnode;
    }
}
int deletion(void)
{
    int val;
    stack *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("Stack Underflow\n\n");
        return -1;
    }
    else
    {
        if (top == start)
        {
            val = ptr->data;
            start = top = NULL;
            free(ptr);
            return val;
        }
        else
        {
            val = ptr->data;
            top = top->link;
            free(ptr);
            return val;
        }
    }
}
void display(void)
{
    stack *ptr;
    ptr = top;
    printf("----------Stack elements--------\n\n");
    printf("top->");
    while (ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    if (top == NULL)
    {
        printf(" <Empty>\n\n");
    }
    printf("\n");
}