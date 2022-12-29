#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *start = NULL;
node *last = NULL;
void insertionFirst(int value);
void insertionLast(int value);
int search(void);
int deletionAtFront(void);
// int deletionAtEnode(void);
void display(void);

int main()
{
    int choice, data, pos, found;

    do
    {
        printf("\n********MENU********\n");
        printf("Press 1: Insertion at first\n");
        printf("Press 2: Insertion at last\n");
        printf("Press 3: search data\n");
        printf("Press 4: Deletion\n");
        printf("Press 5: Display Data\n");
        printf("Press 0: Exit\n");
        printf("-------------------------\n\n");
        printf("Enter Your Option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the data: ");
            scanf("%d", &data);
            insertionFirst(data);
            break;
        }
        case 2:
        {
            printf("Enter the data: ");
            scanf("%d", &data);
            insertionLast(data);
            break;
        }
        case 3:
        {

            found = search();
            if (found == -1)
            {
                printf("Data Not Found !\n");
            }
            else
            {
                printf("Data found\n");
            }
            break;
        }

        case 4:
        {
            printf("Deleted Data [%d]", deletionAtFront());
            break;
        }
        case 5:
        {
            printf("\n--------Listed Elements are-------\n\n");
            display();
            break;
        }

        default:
            printf("Have a nice data\n");
        }

    } while (choice != 0);

    return 0;
}

void insertionFirst(int data)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (start == NULL)
    {
        newnode->data = data;
        start = newnode;
        newnode->link = newnode; // Null
        last = newnode;          // store the last node address
    }
    else
    {
        newnode->data = data;
        newnode->link = start;
        start = newnode;
        last->link = newnode;
    }
}
void insertionLast(int data)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    last->link = newnode;
    last = newnode;
    newnode->link = start;
}
int search(void)
{
    node *ptr;
    int val, pos;
    pos = 1;
    ptr = start;
    printf("Enter the data to be searched: ");
    scanf("%d", &val);
    do
    {
        if (ptr->data == val)
            return 0;
        else
        {
            pos++;
            ptr = ptr->link;
        }
    } while (ptr != start);

    return -1;
}
int deletionAtFront(void)
{
    int data;
    node *ptr;
    ptr = start;
    if (ptr->link == start)
    {
        data = ptr->data;
        free(ptr);
        return data;
    }
    else
    {
        data = ptr->data;
        start = ptr->link;
        last->link = start;
        free(ptr);
        return data;
    }
}
void display(void)
{
    node *ptr;
    ptr = start;
    printf("Start");
    do
    {
        printf("->%d ", ptr->data);
        ptr = ptr->link;
    } while (ptr != start);
}
