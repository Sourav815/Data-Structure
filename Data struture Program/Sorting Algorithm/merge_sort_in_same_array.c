#include <stdio.h>

void merge_sort(int low, int mid, int high, int arr[]);
void divide_merge(int low, int high, int arr[]);

int main()
{
    int A[10], m;
    printf("Enter the number of elements to be stored in A[i] array: ");
    scanf("%d", &m);
    printf("Enter the elements one by one into A[i] array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &A[i]);
    }
    divide_merge(0, m - 1, A);
    printf("------Merged Sorted List------\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
void divide_merge(int low, int high, int arr[])
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        divide_merge(low, mid, arr);
        divide_merge(mid + 1, high, arr);
        merge_sort(low, mid, high, arr);
    }
}
void merge_sort(int low, int mid, int high, int arr[])

{
    int i, j, k, B[20];
    i = low;
    j = mid + 1;
    k = low;
    while ((i <= mid) && (j <= high))
    {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }
    while (i <= mid)
        B[k++] = arr[i++];
    while (j <= high)
        B[k++] = arr[j++];
    int r = low;
    while (r < k)
    {
        arr[r] = B[r];
        r++;
    }
}