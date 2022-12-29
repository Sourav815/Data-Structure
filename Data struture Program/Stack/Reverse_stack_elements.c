#include <stdio.h>
#define max 20
int top = -1;
int stack[20];
int array[20];
int count = 0;

void push_data(int stack[], int item);
int reverse_stack(int stack[], int array[]);

void display(int rev_array[]) {
  printf("\n-------------Reverse Stack elements are----------\n");
  for (int i = 0; i < count; i++)
    printf("%d ", rev_array[i]);
  printf("\n");
}

int main(void) {
  int data, pop_value, check;
  while (check != 0) {
    printf("-------------------------------\n");
    printf("Press 1 Push Data: \n");
    printf("Press 2 reverse Data: \n");
    printf("Press 3 Display: \n");

    printf("Press 0 Exit: \n");
    printf("-------------------------------\n\n");
    printf("Please enter your choice: ");
    scanf("%d", &check);
    switch (check) {
    case 1:
      printf("\nEnter the data: ");
      scanf("%d", &data);
      push_data(stack, data);
      break;
    case 2:
      pop_value = reverse_stack(stack, array);
      if (pop_value == 0)
        printf("revese successful\n");
      break;
    case 3:
      display(array);
      count = 0;
      break;
    default:
      printf("Have a good day");
    }
  }

  return 0;
}
void push_data(int stack[], int data) {
  if (top == max)
    printf("Overflow\n");
  else {
    top++;
    stack[top] = data;
    count++;
  }
}
int reverse_stack(int stack[], int array[]) {
  if (top == -1) {
    printf("Underflow\n");
    return -1;
  } else {
    for (int i = 0; i < count; i++) {
      array[i] = stack[top];
      top--;
    }
    // printf("value of conunt %d\n", count);
    return 0;
  }
}