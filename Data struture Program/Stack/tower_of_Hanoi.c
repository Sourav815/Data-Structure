#include <stdio.h>
int count = 1;
void Move(int source, int destination, int spare, int n) {
  if (n == 1) {
        printf("Move %c to %c using %c spare %d\n",source,destination,spare,count++);
  } else {
    Move(source, spare, destination, n - 1);
    Move(source, destination, spare, 1);
    Move(spare, destination, source, n - 1);
  }
}

int main() {
  int n;
  printf("Enter the number of rings: ");
  scanf("%d", &n);
  Move('A', 'C', 'B', n);
  return 0;
}