#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int Queue[MAX];
int f = -1,
int r = -1;
void insertfront(int element)
 {
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
 {
        printf("Queue is full\n");
        return;
    }
    if (f == -1) 
 {
     f = r = 0;
    } 
 else if (f == 0)
  {
        f = MAX - 1;
    }
 else 
 {
        f--;
    }
    Queue[f] = element;
    printf("%d inserted at front.\n", element);
 }

void insertRear(int item) {
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
 {
        printf("Queue is full.\n");
        return;
    }
    if (f == -1)
  {
        f = r = 0;
    } 
 else if (r == MAX - 1)
  {
        r = 0;
    } 
 else {
        r++;
    }
    Queue[r] = element;
    printf("%d inserted at rear.\n", element);
}

void deleteFront()
 {
    if (f == -1)
 {
        printf("Queue is empty.\n");
        return;
    }
    printf("%d deleted from front.\n", Queue[f]);
    if (f == r) 
   {
        f = r = -1;
    } 
   else if (f == MAX - 1)
  {
        f = 0;
    }
  else 
  {
        f++;
    }
}

void deleteRear() {
    if (f == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("%d deleted from rear.\n", Queue[r]);
    if (f == r)
 {
        f = r = -1;
    } 
else if (r == 0) 
{
        r = MAX - 1;
    } 
else 
{
        r--;
    }
}

void displayQueue() {
    if (f == -1)
  {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    if (f <= r)
  {
        while (i <= r)
  {
            printf("%d ", Queue[i]);
            i++;
        }
    }
 else 
  {
        while (i < MAX)
   {
            printf("%d ", Queue[i]);
            i++;
        }
        i = 0;
        while (i <= r)
   {
            printf("%d ", Queue[i]);
            i++;
        }
    }
    printf("\n");
}

int main() {
    int choice, elements;

    while (1) {
        printf("\n------ Double Ended Queue Operations ------\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayQueue();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
