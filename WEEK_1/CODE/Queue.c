/*
 * linear_queue.c
 *
 * Simple Linear Queue implementation in C.
 *
 * Features:
 *  - Enqueue and Dequeue operations
 *  - Checks for Overflow and Underflow
 *  - Display queue elements
 *
 * Author: Surendar.k
 * GitHub: https://github.com/Surendar7550/PHYTEC_PROJECT_TASKS//WEEK_1/CODE/Queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Queue size

int queue[SIZE];
int front = -1, rear = -1;

// Insert element into the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow)!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Remove element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow)!\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

// Display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// === MAIN ===
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue(); // Should show underflow

    return 0;
}

/*
 * === EXPECTED OUTPUT ===
 *
 * Inserted: 10
 * Inserted: 20
 * Inserted: 30
 * Queue elements: 10 20 30
 * Deleted: 10
 * Queue elements: 20 30
 * Deleted: 20
 * Deleted: 30
 * Queue is empty (Underflow)!
 */
