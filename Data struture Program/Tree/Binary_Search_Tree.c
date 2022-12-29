#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

struct node *root = NULL;

struct node *newNodeCreate(int val);
void treeCreate(int val);
void preOrderDisplay(node *root);
void inorderDisplay(node *root);
void postOrderDisplay(node *root);
node *searchElement(node *root, int val);
void delete (int val);
struct node *inorderPre(struct node *tree);

int main()
{
    int choice, val, result;
    node *temp = NULL;
    do
    {
        printf("*********MENU******\n");
        printf("Press 1: Create Binary Tree\n");
        printf("Press 2: InorderDisplay\n");
        printf("Press 3: PreOrder Display\n");
        printf("Press 4: PostOrder Display\n");
        printf("Press 5: Search Element\n");
        printf("Press 6: Delete Element\n");
        printf("Press 0: Exit\n");
        printf("--------------------\n\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the data: ");
            scanf("%d", &val);
            printf("\n\n");
            treeCreate(val);
            break;
        }
        case 2:
        {
            printf("\n-----Inorder Display------\n");
            inorderDisplay(root);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("\n-----PreOrder Display------\n");
            preOrderDisplay(root);
            printf("\n");
            break;
        }
        case 4:
        {
            printf("\n-----Post Order Display------\n");
            postOrderDisplay(root);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("Enter the data to be found: ");
            scanf("%d", &val);
            temp = searchElement(root, val);
            if (temp == NULL)
            {
                printf("Data NOt found!\n");
            }
            else
            {
                printf("Data found \n");
            }

            printf("\n");
            break;
        }
        case 6:
        {
            printf("\nEnter the data to delete: \n");
            scanf("%d", &val);
            delete (val);
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

struct node *newNodeCreate(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void treeCreate(int val)
{
    node *preptr, *ptr;
    if (root == NULL)
    {
        root = newNodeCreate(val);
    }
    else
    {
        ptr = root;
        preptr = NULL;
        while (ptr != NULL)
        {
            preptr = ptr;
            if (val >= ptr->data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        if (val >= preptr->data)
        {
            preptr->right = newNodeCreate(val);
            // printf("----- %d\n", preptr->right);
        }
        else
        {
            preptr->left = newNodeCreate(val);
            // printf("----- %d\n", preptr->left);
        }
    }
}
void preOrderDisplay(node *root)
{
    if (root != NULL)
    {
        printf("->%d ", root->data);
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
    }
}
void inorderDisplay(node *root)
{
    if (root != NULL)
    {
        inorderDisplay(root->left);
        printf("->%d ", root->data);
        inorderDisplay(root->right);
    }
}
void postOrderDisplay(node *root)
{
    if (root != NULL)
    {
        postOrderDisplay(root->left);
        postOrderDisplay(root->right);
        printf("->%d ", root->data);
    }
}
node *searchElement(node *root, int val)
{
    if (root != NULL)
    {
        if (val > root->data)
        {
            searchElement(root->right, val);
        }
        else if (root->data == val)
        {
            return root;
        }
        else
        {
            searchElement(root->left, val);
        }
    }
}
void delete (int val)
{
    
}
struct node *inorderPre(struct node *tree)
{
    struct node *preptr, *ptr;
    ptr = tree;
    preptr = tree;
    while (ptr != NULL)
    {
        preptr = ptr;
        ptr = ptr->right;
    }
    return preptr;
}