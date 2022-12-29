#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int data;
  struct queue *link;
} Q;
Q *front = NULL;
Q *rear = NULL;

void insertion(int data);
int deletion(void);
void display(void);

int main(void) {

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
      insertion(val);
      break;
    }
    case 2: {
      result = deletion();
      if (result != -1) {
        printf("Deleted element is %d\n\n", result);
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

void insertion(int val) {
  Q *newnode;
  newnode = (Q *)malloc(sizeof(Q));
  newnode->data = val;
  newnode->link = NULL;
  if (front == NULL & rear == NULL) {
    front = rear = newnode;
  } else {
    rear->link = newnode;
    rear = newnode;
  }
}
int deletion(void) {
  int temp;
  Q *ptr;
  ptr = front;
  if (front == NULL & rear == NULL) {
    printf("Queue Underflow\n\n");
    return -1;
  } else {
    if (front == rear) {
      temp = ptr->data;
      front = rear = NULL;
      free(ptr);
      return temp;
    } else {
      temp = ptr->data;
      front = ptr->link;
      free(ptr);
      return temp;
    }
  }
}

void display(void) {
  Q *ptr;
  ptr = front;
  printf("Front");
  while (ptr != NULL) {
    printf("->%d ", ptr->data);
    ptr = ptr->link;
  }
  printf("<-Rear\n");
}