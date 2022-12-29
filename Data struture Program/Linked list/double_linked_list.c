#include <stdio.h>
#include <stdlib.h>

typedef struct double_linked_list
{
    struct double_linked_list *left;
    int data;
    struct double_linked_list *right;
} DLL;

DLL *head = NULL;
DLL *tail = NULL;

void creation(int val);
void insertion(int val);
int deletion(void);
void display(void);
void displayReverse(void);
void recursiveDisplay(DLL *head);
int searchItem(int val);

int main()
{
    int choice, val, result;
    do
    {
        printf("*********MENU******\n");
        printf("Press 1: Create Double Linked list\n");
        printf("Press 2: Insert Data\n");
        printf("Press 3: Delete Data\n");
        printf("Press 4: Display Data\n");
        printf("Press 5: Display Reverse\n");
        printf("Press 6: Display Data Recursively\n");
        printf("Press 7: Search an Item\n");
        printf("Press 0: Exit\n");
        printf("--------------------\n\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the data to store in first node: ");
            scanf("%d", &val);
            creation(val);
            break;
        }
        case 2:
        {
            printf("Enter the data to store: ");
            scanf("%d", &val);
            insertion(val);
            break;
        }

        case 3:
        {
            result = deletion();
            if (result != -1)
            {
                printf("Deleted element is %d\n", result);
            }
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            displayReverse();
            break;
        }
        case 6:
        {
            recursiveDisplay(head);
            printf("\n");
            break;
        }
        case 7:
        {
            printf("Enter the data to be searched: ");
            scanf("%d", &val);
            result = searchItem(val);
            if (result != -1)
            {
                printf("Data found in position [%d]", result);
            }
            else
                printf("Data not fount");

            printf("\n");
            break;
        }

        default:
            printf("Have a nice day\n");
            break;
        }

    } while (choice != 0);
    return 0;
}

void creation(int value)
{
    DLL *node = (DLL *)malloc(sizeof(DLL));
    node->data = value;
    node->right = NULL;
    node->left = NULL;
    if (head == NULL)
    {
        head = tail = node;
    }
    else
    {
        printf("Linked list already created please insert data...\n");
    }
}

void insertion(int val)
{
    DLL *node = (DLL *)malloc(sizeof(DLL));
    DLL *ptr, *preptr;
    ptr = head;
    node->data = val;
    node->right = NULL;
    ptr = head;
    preptr = NULL;
    while (ptr != NULL)
    {
        preptr = ptr;
        ptr = ptr->right;
    }
    preptr->right = node;
    tail = node;
    node->left = preptr;
}
int deletion(void)
{
    int val;
    DLL *ptr, *temp;
    temp = NULL;
    printf("Enter the value to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr != NULL)
    {
        if (val == ptr->data)
        {
            if (ptr == head)
            {
                head = ptr->right;
                ptr->right->left = NULL;
                free(ptr);
                return val;
            }
            {
                temp = ptr->left;
                temp->right = ptr->right;
                ptr->right->left = temp;
                free(ptr);
                return val;
            }
        }
        else
            ptr = ptr->right;
    }
    return -1;
}
void display(void)
{
    DLL *ptr;
    ptr = head;
    printf("head ");
    while (ptr != NULL)
    {
        printf("->%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}
void displayReverse(void)
{
    DLL *ptr;
    ptr = tail;
    printf("Reverse ");
    while (ptr != NULL)
    {
        printf("->%d ", ptr->data);
        ptr = ptr->left;
    }
    printf("\n");
}
void recursiveDisplay(DLL *ptr)
{

    if (ptr != NULL)
    {
        printf("->%d", ptr->data);
        recursiveDisplay(ptr->right);
    }
}
int searchItem(int val)
{
    DLL *ptr = NULL;
    int count = 1;
    ptr = head;
    while (ptr != NULL)
    {
        if (val == ptr->data)
        {
            return count;
        }
        else
        {
            ptr = ptr->right;
            count++;
        }
    }
    return -1;
}
