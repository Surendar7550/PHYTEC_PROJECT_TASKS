/*
 * linked_list.c
 *
 * Simple Singly Linked List implementation in C.
 *
 * Features:
 *  - Initialize linked list with first node
 *  - Add node at beginning
 *  - Add node at end
 *  - Traverse and display nodes
 *
 * Author: Surendar.k
 * GitHub: https://github.com/Surendar7550/PHYTEC_PROJECT_TASKS/WEEK_1/CODE/Linked_list.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
typedef struct node {
    int data;
    struct node *next;
} __attribute__((packed)) node_s;

node_s *head = NULL;

// Initialize linked list with first node
int init(int data) {
    if (head != NULL) {
        printf("List already created\n");
        return -1;
    }
    head = malloc(sizeof(node_s));
    if (head == NULL) {
        printf("Memory not allocated\n");
        return -2;
    }
    head->data = data;
    head->next = NULL;
    printf("Initialized list with data: %d\n", data);
    return 0;
}

// Add node at beginning
int add(int data) {
    node_s *new_node = malloc(sizeof(node_s));
    if (new_node == NULL) {
        printf("Memory not allocated\n");
        return -2;
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    printf("Added at beginning: %d\n", data);
    return 0;
}

// Add node at end
int add_at_end(int data) {
    node_s *n = malloc(sizeof(node_s));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    n->data = data;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        printf("Added at end as first node: %d\n", data);
        return 0;
    }

    node_s *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = n;
    printf("Added at end: %d\n", data);
    return 0;
}

// Traverse and display linked list
int traverse() {
    if (!head) {
        printf("List is empty\n");
        return -1;
    }
    printf("Linked List: ");
    for (node_s *cur = head; cur != NULL; cur = cur->next) {
        printf("%d --> ", cur->data);
    }
    printf("NULL\n");
    return 0;
}

// === MAIN ===
int main() {
    init(100);
    init(22); // Should show already created

    add(10);
    add(20);
    add(30);

    add_at_end(200);
    add_at_end(300);
    add_at_end(400);

    traverse();

    return 0;
}

/*
 * === EXPECTED OUTPUT ===
 *
 * Initialized list with data: 100
 * List already created
 * Added at beginning: 10
 * Added at beginning: 20
 * Added at beginning: 30
 * Added at end: 200
 * Added at end: 300
 * Added at end: 400
 * Linked List: 30 --> 20 --> 10 --> 100 --> 200 --> 300 --> 400 --> NULL
 */
