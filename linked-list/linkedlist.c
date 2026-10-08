#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node *next;
};

struct Node *node_init(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
};

void node_free(struct Node *node) {
    while(node) {
        struct Node *temp = node->next;
        free(node);
        node = temp;
    };
}

void node_append(struct Node *node, int value) {
    while(node->next) {
        node = node->next;
    };
    node->next = node_init(value);
};

void traverse(struct Node *node) { 
    while(node) {
        printf("%d\n", node->value);
        node = node->next;
    };
};

int main() {
   
    struct Node *node1 = node_init(2);    
    node_append(node1, 3);
    node_append(node1, 4);
    
    
    traverse(node1);
    node_free(node1);
    
    return 0;
};
