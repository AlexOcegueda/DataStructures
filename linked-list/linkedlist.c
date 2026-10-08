#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

void traverse(struct Node *node) { 
    while(node->next) {
        printf("%d\n", node->value);
        node = node->next;
    };
};

int main() {
    
    struct Node node1;
    struct Node node2;
    struct Node node3;
    struct Node node4;

    node1.value = 1;
    node2.value = 2;
    node3.value = 3;
    node4.value = 4;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;

    traverse(&node1);
    return 0;
};
