#include <stdio.h>

int main()
{
    int arr[10] = {'\0'};
    for (int i = 1; i < 10; i = (i * 2))
    {
        scanf("%d", &arr[i]);
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == '\0')
        {
            printf("hi\n");
        }
        else
            printf("%d\n", arr[i]);
    }

    return 0;
}