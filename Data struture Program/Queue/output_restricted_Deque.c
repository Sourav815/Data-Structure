#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;

void insertionFront(int value);
void insertionEnd(int value);
int deletion(void);
void display(void);

int main() {
  int check, num, return_value;

  do {
    printf("\n********** Menu *********\n\n");
    printf("Press 1 for Insertion data into Front\n");
    printf("Press 2 for Insertion data into End\n");
    printf("Press 3 for Delete data\n");
    printf("Press 4 for Display data\n");
    printf("Press 0 for Exit\n");
    printf("----------------------------\n\n");
    printf("Enter your choice: ");
    scanf("%d", &check);
    switch (check) {
    case 1: {
      printf("Enter the data to store in Queue: ");
      scanf("%d", &num);
      insertionFront(num);
      break;
    }
    case 2: {
      printf("Enter the data to store in Queue: ");
      scanf("%d", &num);
      insertionEnd(num);
      break;
    }

    case 3: {
      return_value = deletion();
      if (return_value == -1)
        printf("\n\t!!! Underflow !!!\n");
      else
        printf("\nData is deleted... [%d]\n", return_value);
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
void insertionFront(int value) {
  if (rear >= max - 1 && front == 0) {
    printf("\n\t!!! OverFlow !!!\n");
  } else {
    if (front == -1 && rear == -1) {
      front = rear = 0;
      queue[front] = value;
    } else if (front == 0) {
      printf("\nSorry! can't insert...\n");
      return;
    } else if (front > 0) {
      front--;
      queue[front] = value;
    }
  }
}
void insertionEnd(int value) {
  if (rear >= max - 1) {
    printf("\n\t!!! <OverFlow End>!!!\n");
  } else {
    if (front == -1 && rear == -1) {
      front = rear = 0;
    } else {
      rear++;
    }
    queue[rear] = value;
  }
}

int deletion(void) {
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
void display(void) {
  printf("\n--------Display Queue----------\n\n");
  if (front > 0) {
    for (int i = 0; i < front; i++) {
      printf("*\n", queue[i]);
    }
  }
  if (front <= rear && front != -1 && rear != -1) {
    for (int i = front; i <= rear; i++) {
      printf("%d\n", queue[i]);
    }
  }
  if (rear != max - 1) {
    for (int i = rear; i < max - 1; i++) {
      printf("*\n", queue[i]);
    }
  }
}