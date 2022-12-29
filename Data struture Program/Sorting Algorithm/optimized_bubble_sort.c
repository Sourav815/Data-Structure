#include <stdio.h>
#define max 10

void bubble_sort(int *arr, int n)
{
    int temp = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Array is already sorted\n");
            return;
        }
    }
    printf("\nSorted Data are-----------\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{
    int arr[max], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    return 0;
}