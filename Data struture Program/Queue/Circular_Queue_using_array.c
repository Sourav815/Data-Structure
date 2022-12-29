#include <stdio.h>
#define max 3

int queue[max];
int front = -1, rear = -1;

void insertion(int value);
int deletion(void);
void display(void);

int main() {
  int check, num, return_value;

  do {
    printf("\n------------Menu-----------\n\n");
    printf("Press 1 for Insertion data\n");
    printf("Press 2 for Delete data\n");
    printf("Press 3 for Display data\n");
    printf("Press 0 for Exit\n");
    printf("----------------------------\n\n");
    printf("Enter your choice: ");
    scanf("%d", &check);
    switch (check) {
    case 1: {
      printf("Enter the data to store in Queue: ");
      scanf("%d", &num);
      insertion(num);
      break;
    }
    case 2: {
      return_value = deletion();
      if (return_value == -1)
        printf("\tUnderflow");
      else
        printf("Deleted data is %d\n", return_value);
      break;
    }
    case 3: {
      display();
      break;
    }
    default:
      printf("Have a good day!\n");
    }

  } while (check != 0);

  return 0;
}
void insertion(int value) {
  if ((rear + 1) % max == front) {
    {
      printf("!!! OverFlow !!!\n");
      return;
    }
  } else {
    if (front == -1 && rear == -1) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % max;
    }
    queue[rear] = value;
  }
}

int deletion(void) {
  int data;
  if (front == -1 && rear == -1)
    return -1;
  else {
    data = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % max;
    }
  }
  return data;
}
void display(void) {
  if (front != -1 && rear != -1) {
    printf("\n--------Display Queue----------\n\n");
    if (front <= rear) {
      for (int i = front; i <= rear; i++)
        printf("\t%d", queue[i]);
    } else {
      for (int i = front; i < max; i++)
        printf("\t%d", queue[i]);
      for (int i = 0; i <= rear; i++)
        printf("\t%d", queue[i]);
    }
  }
  else
    printf("-----Queue is Empty-------\n");
}