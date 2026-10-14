#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    struct Node *front;
  	struct Node *back;
};

struct Node {
    int value;
    struct Node *next;
};

struct Queue *queue_init() {
    struct Queue *q = malloc(sizeof(struct Queue)); 
    
    if(q == NULL) {
        return NULL;
    }

    q->front = NULL;
    q->back = NULL;
		return q;
};	

void queue_enqueue(struct Queue *q, int value) {
    struct Node *node = malloc(sizeof(struct Node));
    
    if(node == NULL) {
        return;
    };

    node->value = value;
    node->next = NULL;

    if(q->front == NULL) { 
        q->front = node;
        q->back = node;
    } else {
        q->back->next = node;
        q->back = node;
    };
};

bool queue_is_empty(struct Queue *q) {

    if(q->front == NULL) {
        return true;
    };
    return false;
};

struct Queue *queue_dequeue(struct Queue *q) {
    if(queue_is_empty(q)) {
        return q;
    };

    // one node
    if(q->front == q->back) {
        free(q->front);
        q->front = NULL;
        q->back = NULL;
        return q;
    };

    struct Node *node = q->front->next;
    free(q->front);
    q->front = node;
    return q;
};

int queue_peek(struct Queue *q) { 
    if(queue_is_empty(q)) {
        return -1; 
    };
    return q->front->value;
};

void queue_free(struct Queue *q) {
    struct Node *current = q->front;

    while(current) {
        struct Node *temp = current->next;
        free(current);
        current = temp;
    };
    free(q);
};

void traverse(struct Queue *q) {
    struct Node *current = q->front;
    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    };
};

int main() {
		struct Queue *q = queue_init();
    //queue_enqueue(q, 1); 
    //queue_enqueue(q, 2); 
    //queue_enqueue(q, 3); 
    q = queue_dequeue(q);
    printf("Peeked: %d\n", queue_peek(q));
    //q = queue_dequeue(q);
    //traverse(q);
    queue_free(q);
    return 0;
};
