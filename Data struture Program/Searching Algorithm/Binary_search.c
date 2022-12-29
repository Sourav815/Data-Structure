#include <stdio.h>

void binary_search(int *ptr, int n, int num) {
  int beg, end, mid, found = 0;
  beg = 0;
  end = n - 1;
  while (beg <= end) {
    mid = (beg + end) / 2;
    if (num == ptr[mid]) {
      printf("Data found successfully at position %d\n", mid + 1);
      found = 1;
      break;
    } else if (num > ptr[mid])
      beg = mid + 1;
    else
      end = mid - 1;
  }
  if (found == 0)
    printf("Data is not found...\n");
}

int main(void) {
  int arr[10], n, num, result;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  printf("Enter the array elements (assending order): ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the number to be searched: ");
  scanf("%d", &num);
  binary_search(arr, n, num);
  return 0;
}
