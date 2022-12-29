#include <stdio.h>

int linear_searchi(int *arr,int n,int num);
int main(void) {
  int arr[10],n,num,result;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  printf("Enter the array elements: ");
  for(int i= 0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  printf("Enter the number to be searched: ");
  scanf("%d",&num);
  result=linear_searchi(arr,n,num);
  if(result == -1)
    printf("Data not found...");
  else
    printf("%d is found at position %d",num,result);
  return 0;
}
int linear_searchi(int *arr,int n,int num)
{
  for(int i = 0;i<n;i++)
    {
      if(num==arr[i])
      {
        return(i+1);
      }
    }
  return -1;
}