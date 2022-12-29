#include <stdio.h>
#define max 3

int queue[max];
int front = -1, rear = -1;

void insertion(int queue[], int value);
int deletion(int queue[]);
void display(int queue[]);

int main(void) { 
  int check,num,return_value;

  do{
    printf("\n------------Menu-----------\n");
    printf("Press 1 for Insertion data\n");
    printf("Press 2 for Delete data\n");
    printf("Press 3 for Display data\n");
    printf("Press 0 for Exit\n");
    printf("----------------------------\n\n");
    printf("Enter your choice: ");
    scanf("%d",&check);
    switch(check){
      case 1:
        {
          printf("Enter the data to store in Queue: ");
          scanf("%d",&num);
          insertion(queue,num);
          break;
        }
      case 2:
        {
          return_value = deletion(queue);
          if(return_value == -1)
            printf("\tUnderflow");
          else
            printf("Deleted data is %d\n",return_value);
          break;
        }
      case 3:
        {
          display(queue);
          break;
        }
      default:
        printf("Have a good day!\n");
    }

  }while(check!=0);

  
  return 0; 
  }

void insertion(int queue[], int value) {
  if (rear >= max - 1)
    printf("\tOverflow\n");
  else if (front == -1 && rear == -1) {
    front++;
    rear++;
    queue[rear] = value;
  } else {
    rear++;
    queue[rear] = value;
  }
}
int deletion(int queue[]) {
  int data;
  if (front == -1 || front > rear)
    return -1;
  else {
    data = queue[front];
    front++;
    if(front>rear)
      front = rear = -1;
    return data;
  }
}

void display(int queue[]) {
  printf("\n-----------Data in Queue--------\n");
  for (int i = front; i <= rear; i++) {
    printf("\t%d", queue[i]);
  }
}