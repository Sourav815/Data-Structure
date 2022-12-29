// Circular Queue

#include <stdio.h>
#define max 3

int cqueue[max];
int front = 0, rear = 0;

void insert_data(int);
int Delete(void);
void display(void);

int main() {

  int choice, val, result;
  do {
    printf("*********MENU******\n");
    printf("Press 1: Insert Data\n");
    printf("Press 2: Delete Data\n");
    printf("Press 3: Display Data\n");
    printf("Press 0: Exit\n");
    printf("--------------------\n");
    printf("Enter your option: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      printf("Enter the data to store: ");
      scanf("%d", &val);
      insert_data(val);
      break;
    }
    case 2: {
      result = Delete();
      if (result != -1) {
        printf("Deleted element is %d\n", result);
      }
      break;
    }
    case 3: {
      display();
      break;
    }

    default:
      printf("Have a nice day\n");
      break;
    }

  } while (choice != 0);

  return 0;
}

void insert_data(int data) {
  if ((rear + 1) % max == front) {
    printf("Queue is overflow\n");
  } else {
    cqueue[rear] = data;
    rear = (rear + 1) % max;
  }
}

int Delete(void) {
  int val;
  if (front == rear) {
    printf("Queue Underflow\n");
    return -1;
  } else {
    val = cqueue[front];
    front = (front + 1) % max;
    return val;
  }
}

void display(void) {
  printf("---------Data in Queue---------\n");
  printf("Front-> ");
  for (int i = front; i != rear; i = (i + 1) % max) {
    printf("%d ", cqueue[i]);
  }
  printf("<-Rear");
  printf("\n\n");
}