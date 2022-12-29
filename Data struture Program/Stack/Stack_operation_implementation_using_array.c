#include <stdio.h>
#define max 20
int top = -1;
int array[max];
void push_data(int array[], int item);
int pop_data(int array[]);
int peek_data(int array[]);
void display(int array[]) {
  printf("\n-------------Stack elements are----------\n");
  for (int i = 0; i <= top; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main(void) {
  int data, pop_value, peek_value, check;
  while (check != 0) {
    printf("-------------------------------\n");
    printf("Press 1 Push Data: \n");
    printf("Press 2 pop Data: \n");
    printf("Press 3 peek Data: \n");
    printf("Press 4 Display Stack Data: \n");
    printf("Press 0 Exit: \n");
    printf("-------------------------------\n\n");
    printf("Please enter your choice: ");
    scanf("%d", &check);
    switch (check) {
    case 1:
      printf("\nEnter the data: ");
      scanf("%d", &data);
      push_data(array, data);
      break;
    case 2:
      pop_value = pop_data(array);
      if (pop_value != -1)
        printf("Popped data is %d\n", pop_value);
      break;
    case 3:
      peek_value = peek_data(array);
      if (peek_value != -1)
        printf("Peeked data is %d\n", peek_value);
      break;
    case 4:
      display(array);
      break;
    default:
      printf("Have a good day");
    }
  }

  return 0;
}
void push_data(int array[], int data) {
  if (top == max)
    printf("Overflow\n");
  else {
    top++;
    array[top] = data;
  }
}
int pop_data(int array[]) {
  int data;
  if (top == -1) {
    printf("Underflow\n");
    return -1;
  } else {
    data = array[top];
    top--;
    return data;
  }
}
int peek_data(int array[]) {
  if (top == -1)
    printf("Stack Underflow");
  else
    return array[top];
}