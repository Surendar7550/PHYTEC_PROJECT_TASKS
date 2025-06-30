#include <stdio.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front > q->rear;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

// Enqueue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int value = q->items[q->front];
        q->front++;
        printf("Dequeued: %d\n", value);
        return value;
    }
}

// Display
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Should say empty

    return 0;
}
