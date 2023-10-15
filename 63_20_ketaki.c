#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;
} PriorityQueue;
void initializePriorityQueue(PriorityQueue* queue) {
    queue->size = 0;
}
int isEmpty(PriorityQueue* queue) {
    return (queue->size == 0);
}
int isFull(PriorityQueue* queue) {
    return (queue->size == MAX_SIZE);
}
void enqueue(PriorityQueue* queue, int element, int priority) {
    if (isFull(queue)) {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }

    int index = queue->size;
    while (index > 0 && priority > queue->priorities[index - 1]) {
        queue->data[index] = queue->data[index - 1];
        queue->priorities[index] = queue->priorities[index - 1];
        index--;
    }

    queue->data[index] = element;
    queue->priorities[index] = priority;
    queue->size++;
}
int dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1; // You can handle errors differently
    }

    int element = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
        queue->priorities[i - 1] = queue->priorities[i];
    }

    queue->size--;
    return element;
}
void printPriorityQueue(PriorityQueue* queue) {
    printf("Priority Queue Contents:\n");
    for (int i = 0; i < queue->size; i++) {
        printf("Element: %d, Priority: %d\n", queue->data[i], queue->priorities[i]);
    }
}

int main() {
    PriorityQueue queue;
    initializePriorityQueue(&queue);

    enqueue(&queue, 5, 2);
    enqueue(&queue, 8, 1);
    enqueue(&queue, 3, 3);

    printPriorityQueue(&queue);

    int highestPriorityElement = dequeue(&queue);
    printf("Dequeued Element with Highest Priority: %d\n", highestPriorityElement);

    printPriorityQueue(&queue);

    return 0;
}
