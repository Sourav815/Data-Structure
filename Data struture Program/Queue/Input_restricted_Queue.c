#include <stdio.h>
#define max 4

int queue[max];
int front = -1, rear = -1;

void insertion(int value);
int deletionFront(void);
int deletionEnd(void);
void display(void);

int main() {
  int check, num, return_value;

  do {
    printf("\n********** Menu *********\n\n");
    printf("Press 1 for Insertion data\n");
    printf("Press 2 for Delete data from Front\n");
    printf("Press 3 for Delete data from End\n");
    printf("Press 4 for Display data\n");
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
      return_value = deletionFront();
      if (return_value == -1)
        printf("\n\t!!! Underflow !!!\n");
      else
        printf("\nData is deleted from Front End...[%d]\n", return_value);
      break;
    }
    case 3: {
      return_value = deletionEnd();
      if (return_value == -1)
        printf("\n\t!!! Underflow !!!\n");
      else
        printf("\nData is deleted from Rear End... [%d]\n", return_value);
      break;
    }
    case 4: {
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
  if (rear >= max - 1) {
    printf("\n\t!!! OverFlow !!!\n");
  } else {
    if (front == -1 && rear == -1) {
      front = rear = 0;
    } else {
      rear++;
    }
    queue[rear] = value;
  }
}

int deletionFront(void) {
  int data;
  if (front == -1 || front > rear)
    return -1;
  else {
    data = queue[front];
    front++;
    if (front > rear) {
      front = rear = -1;
    }
  }
  return data;
}
int deletionEnd(void) {
  int data;
  if (rear == -1 || rear < front)
    return -1;
  else {
    data = queue[rear];
    rear--;
    if (rear < front) {
      front = rear = -1;
    }
  }
  return data;
}
void display(void) {
  printf("\n--------Display Queue----------\n\n");
  if (front < rear) {
    for (int i = front; i <= rear; i++) {
      printf("\t%d", queue[i]);
    }
    printf("\n");
  }
}