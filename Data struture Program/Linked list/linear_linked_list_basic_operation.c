#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int data;
    struct nd *link;
} node;

node *start;
void insertion(void);
int deletionAtFront(void);
int deletionAtEnd(void);
int deletion(int);
int search_data(void);
void reverse(node *);
void display(void);

int main()
{
    int choice, pos, found;
    node *rev;
    rev = start;

    do
    {
        printf("\n********MENU********\n");
        printf("Press 1: Insert Data\n");
        printf("Press 2: Delete First Data\n");
        printf("Press 3: Delete Last Data\n");
        printf("Press 4: Delete Data (Any position)\n");
        printf("Press 5: Searching Data\n");
        printf("Press 6: Reverse\n");
        printf("Press 7: Display Data\n");
        printf("Press 0: Exit\n");
        printf("-------------------------\n\n");
        printf("Enter Your Option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insertion();
            break;
        }
        case 2:
        {
            printf("Deleted Data [%d]", deletionAtFront());
            break;
        }
        case 3:
        {
            printf("Deleted Data [%d]", deletionAtEnd());
            break;
        }
        case 4:
        {
            printf("Enter the Position: ");
            scanf("%d", &pos);
            printf("Deleted Data [%d]", deletion(pos));
            break;
        }
        case 5:
        {
            found = search_data();
            if (found == -1)
                printf("Not found !\n");
            else
                printf("Data found at position %d\n", found);
            break;
        }
        case 6:
        {
            printf("\n--------Reversed Elements are-------\n\n");
            printf("Reverse");
            reverse(start);
            break;
        }
        case 7:
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

void insertion(void)
{
    node *newnode, *ptr;
    char check;
    int data;
    newnode = (node *)malloc(sizeof(node));
    start = ptr = newnode;

    while (ptr)
    {
        printf("Enter the data to store: ");
        scanf("%d", &newnode->data);
        printf("Do you want to store more element [Y/N]: ");
        fflush(stdin);
        scanf("%c", &check);
        if (check == 'N' || check == 'n')
        {
            ptr->link = NULL;
            break;
        }
        else
        {
            newnode = (node *)malloc(sizeof(node));
            ptr->link = newnode;
            ptr = newnode;
        }
    }
}
int deletionAtFront(void)
{
    node *ptr;
    ptr = start;
    start = ptr->link;
    return (ptr->data);
}
int deletionAtEnd(void)
{
    node *ptr;
    ptr = start;
    int data;
    while (ptr)
    {
        if (ptr->link->link == NULL)
        {
            data = ptr->link->data;
            ptr->link = NULL;
            return data;
        }
        else
        {
            ptr = ptr->link;
        }
    }
}
int deletion(int pos)
{
    node *ptr, *preptr;
    ptr = start;
    int count = 1, data;
    while (ptr)
    {
        if (count == pos)
        {
            if (pos == 1)
            {
                start = ptr->link;
                data = ptr->data;
                // free(ptr);
                break;
            }
            preptr->link = ptr->link;
            data = ptr->data;
            free(ptr);
            break;
        }
        else
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        count++;
    }
    return data;
}
int search_data(void)
{
    node *ptr;
    int pos, val;
    ptr = start;
    pos = 1;
    printf("Enter the data be searched: ");
    scanf("%d", &val);
    while (ptr)
    {
        if (ptr->data == val)
            return pos;
        else
        {
            pos++;
            ptr = ptr->link;
        }
    }
    return -1;
}
void reverse(node *ptr)
{
    if (ptr)
    {
        reverse(ptr->link);
        printf("->%d ", ptr->data);
    }
}
void display(void)
{
    node *ptr;
    ptr = start;
    printf("start: ");
    while (ptr)
    {
        printf("-> %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n");
}