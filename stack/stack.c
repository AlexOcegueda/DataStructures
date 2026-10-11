#include <stdlib.h>
#include <stdio.h>

struct Node {
	int value;
	struct Node *next;
};

struct Node *node_init(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->next = NULL;
    return node;
};

int node_length(struct Node *node) {
    int length = 0;

    while (node) {
        length++;
        node = node->next;
    }

    return length;
};

void stack_push(struct Node *node, int value) {
  	while(node->next) {
      	node = node->next;
  	};
  	node->next = node_init(value);
};

int stack_pop(struct Node *node) {
    int length = node_length(node);
    for(int i=0; i < length - 1; i++) {
        node = node->next; 
    };
    struct Node *nxt = node->next;
    int popped = nxt->value;
    free(nxt);
    return popped;
};

void traverse(struct Node *node) { 
    while(node) {
        printf("%d\n", node->value);
        node = node->next;
    };
};

int main() {
	struct Node *node = node_init(1); 
	stack_push(node, 2);
	stack_pop(node);
  traverse(node);
	return 0;
};
