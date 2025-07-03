/*
 * circular_buffer.c
 *
 * Simple Circular Buffer implementation in C.
 *
 * Features:
 *  - Enqueue and Dequeue operations
 *  - Check if buffer is full or empty
 *  - Display buffer contents
 *
 * Author: Surendar.k
 * GitHub: https://github.com/Surendar7550/PHYTEC_PROJECT_TASKS/WEEK_1/CODE/Circular_Buffer.c
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE 5  // Buffer size

typedef struct {
    int buffer[SIZE];
    int head;
    int tail;
    int count; // Number of elements in buffer
} CircularBuffer;

// Initialize the buffer
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    printf("Circular Buffer Initialized.\n");
}

// Check if buffer is empty
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// Check if buffer is full
bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// Add item to buffer
bool enqueue(CircularBuffer *cb, int item) {
    if (isFull(cb)) {
        printf("Buffer is full! Cannot enqueue %d\n", item);
        return false;
    }
    cb->buffer[cb->head] = item;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
    printf("Enqueued: %d\n", item);
    return true;
}

// Remove item from buffer
bool dequeue(CircularBuffer *cb, int *item) {
    if (isEmpty(cb)) {
        printf("Buffer is empty! Cannot dequeue\n");
        return false;
    }
    *item = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    printf("Dequeued: %d\n", *item);
    return true;
}

// Display buffer contents
void displayBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer is empty!\n");
        return;
    }
    printf("Buffer contents: ");
    int index = cb->tail;
    for (int i = 0; i < cb->count; i++) {
        printf("%d ", cb->buffer[index]);
        index = (index + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    enqueue(&cb, 10);
    enqueue(&cb, 20);
    enqueue(&cb, 30);
    enqueue(&cb, 40);
    enqueue(&cb, 50); // Buffer should now be full
    displayBuffer(&cb);

    enqueue(&cb, 60); // Should say full

    int item;
    dequeue(&cb, &item);
    dequeue(&cb, &item);
    displayBuffer(&cb);

    enqueue(&cb, 60);
    enqueue(&cb, 70);
    displayBuffer(&cb);

    return 0;
}
/* 
*  === EXPECTED OUTPUT ===
*
*
* Circular Buffer Initialized.
* Enqueued: 10
* Enqueued: 20
* Enqueued: 30
* Enqueued: 40
* Enqueued: 50
* Buffer contents: 10 20 30 40 50 
* Buffer is full! Cannot enqueue 60
* Dequeued: 10
* Dequeued: 20
* Buffer contents: 30 40 50 
* Enqueued: 60
* Enqueued: 70
* Buffer contents: 30 40 50 60 70 
*/
