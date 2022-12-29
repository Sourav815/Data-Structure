#include <stdio.h>

int quick_partition(int low, int high, int arr[]);
void quick_sort(int low, int high, int arr[]);

int main()
{

    return 0;
}

void quick_sort(int low, int high, int arr[])
{
    int q;
    if (low < high)
    {
        q = quick_partition(low, high, arr);
        quick_partition(low, q, arr);
        quick_partition(q + 1, high, arr);
    }
}
int quick_partition(int low, int high, int arr[])
{
    int pivot, i, j;
    pivot = arr[0];
    i = low;
    j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j++;
        } while (arr[i] > pivot);
        if (i<j))
        {
            /* code */
        }
        
    }
}