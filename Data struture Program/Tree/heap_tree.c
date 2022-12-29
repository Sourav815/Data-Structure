#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 15
int arr[max];
int x = -1;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int val)
{
    x += 1;
    arr[x] = val;
    int i = x;
    while (i > 0)
    {
        int parent = ((i - 1) / 2);
        if (arr[parent] < arr[i])
        {
            swap(&arr[parent], &arr[i]);
            i = parent;
        }
        else
            return;
    }
}
void create()
{
    printf("Please enter the size of the array-");
    int n;
    scanf("%d", &n);
    printf("PLease enter the value: ");
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        insert(val);
    }
}
void inorder(int i)
{
    if (i <= x)
    {
        inorder(2 * i + 1);
        printf("%d ", arr[i]);
        inorder(2 * i + 2);
    }
}
void Preorder(int i)
{
    if (i <= x)
    {
        printf("%d ", arr[i]);
        Preorder(2 * i + 1);
        Preorder(2 * i + 2);
    }
}
void Postorder(int i)
{
    if (i <= x)
    {
        Postorder(2 * i + 1);
        Postorder(2 * i + 2);
        printf("%d ", arr[i]);
    }
}
void heapify(int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
        largest = l;
    if (r < n && arr[largest] < arr[r])
        largest = r;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(largest, n);
    }
}
void display()
{
    printf("The heap sorted array is-");
    for (int i = 0; i <= x; i++)
        printf(" %d ", arr[i]);
}
void heap_sort()
{
    for (int i = x; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(0, i);
    }
    display();
}
int main()
{
    while (1)
    {
        printf("\n********Menu********\n");
        printf("Press 1 : To create heap tree\n");
        printf("Press 2 : Inorder Traverse\n");
        printf("Press 3 : Preorder Traverse\n");
        printf("Press 4 : Postorder Traverse\n");
        printf("press 0 : Exit\n");
        printf("-------------------------\n\n");
        int choise;
        printf("Please Enter your choice: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            create();

            break;
        case 2:
            printf("The inorder traversal is: ");
            inorder(0);
            break;
        case 3:
            printf("The postorder traversal is: ");
            Postorder(0);
            break;
        case 4:
            printf("The preorder traversal is: ");
            Preorder(0);
            break;
        case 5:
            heap_sort();
            break;

        default:
            printf("choose currect number----");
        }
    }
    return 0;
}