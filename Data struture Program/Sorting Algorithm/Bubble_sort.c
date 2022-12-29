#include <stdio.h>
#define max 10

int *bubble_sort(int *arr, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // printf("\nSorted Data are-----------\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf(" %d", arr[i]);
    // }
    return arr;
}

int main()
{
    int arr[max], n;
    int *ptr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    ptr = bubble_sort(arr, n);
    printf("\nSorted Data are-----------\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", *(ptr + i));
    }
    return 0;
}