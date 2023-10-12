include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct Node* next;
};
struct Queue 
{
    struct Node* front;
    struct Node* rear;
};
struct Queue* createQueue() 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
int isEmpty(struct Queue* queue)
 {
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue))
   {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
int dequeue(struct Queue* queue)
 {
    if (isEmpty(queue))
 {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
   {
        queue->rear = NULL;
    }
    
    free(temp);
    return data;
 }
 int front(struct Queue* queue)
 {
    if (isEmpty(queue)) 
 {
        printf("Queue is empty\n");
        return -1; 
    }
    return queue->front->data;
 }
 void display(struct Queue* queue)
 {
    struct Node* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
 }
 int main() {
 struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Queue elements: ");
    display(queue);
    printf("Front element: %d\n", front(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue elements after dequeue: ");
    display(queue);
    return 0;
}
}
