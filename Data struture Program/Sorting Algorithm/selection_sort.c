#include <stdio.h>
#define max 10
void seletion_sort(int *arr, int n)
{
    int min, temp = 0, pos, flag = 0;
    for (int i = 0; i < n; i++)
    {
        min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
    printf("--------Sorted elements-----\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
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
    seletion_sort(arr, n);
    return 0;
}