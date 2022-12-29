#include <stdio.h>

int main()
{
    int A[10], B[10], C[20], m, n, i, j, k;
    printf("Enter the number of elements to be stored in A[i] array: ");
    scanf("%d", &m);
    printf("Enter the elements one by one into A[i] array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the number of elements to be stored in B[i] array: ");
    scanf("%d", &n);
    printf("Enter the elements one by one into B[i] array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    i = j = k = 0;
    while ((i < m) && (j < n))
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    if (i < m)
    {
        for (int p = i; p < m; p++)
        {
            C[k++] = A[p];
        }
    }
    else if (j < n)
    {
        for (int p = j; p < n; p++)
        {
            C[k++] = B[p];
        }
    }
    printf("-------Merge Sort -------\n\n");
    for (int i = 0; i < (m + n); i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}