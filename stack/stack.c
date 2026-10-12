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

struct Node *stack_push(struct Node *node, int value) {
    struct Node *pNode = node_init(value);
    pNode->next = node;
    return pNode;

};

int stack_peek(struct Node *node) {
    if(node == NULL) {
        return -1;
    };

    return node->value;
};

struct Node *stack_pop(struct Node *node) {
    if(node == NULL) { 
        return NULL;
    };
    
    struct Node *nxt = node->next;
    free(node);
    return nxt;
};

void traverse(struct Node *node) { 
    while(node) {
        printf("%d\n", node->value);
        node = node->next;
    };
};

int main() {
	  struct Node *node = node_init(1); 
	  node = stack_push(node, 200);
    //traverse(node);
	  printf("%d\n", stack_peek(node));
    

    node = stack_pop(node);
    //node = stack_pop(node);
    //node = stack_pop(node);
    //node = stack_pop(node);
    traverse(node);
	  return 0;
};
