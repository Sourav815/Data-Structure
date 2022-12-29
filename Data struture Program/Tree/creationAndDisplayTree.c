#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

struct node *root = NULL;

void leftNodeCreate(int val);
void rightNodeCreate(int val);
void inorderDisplay(void);

int main()
{
    int choice, val, result;
    do
    {
        printf("*********MENU******\n");
        printf("Press 1: Create Left Node\n");
        printf("Press 2: Create Right Node\n");
        printf("Press 3: Display\n");
        printf("Press 0: Exit\n");
        printf("--------------------\n\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the data to left Node: ");
            scanf("%d", &val);
            printf("\n\n");
            leftNodeCreate(val);
            break;
        }
        case 2:
        {
            printf("Enter the data to left Node: ");
            scanf("%d", &val);
            printf("\n\n");
            rightNodeCreate(val);
            break;
        }
        case 3:
        {
            inorderDisplay();
            break;
        }

        default:
            printf("Have a nice day\n");
            break;
        }

    } while (choice != 0);

    return 0;
}