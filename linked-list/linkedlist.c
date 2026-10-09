#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
}

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

struct Node *node_prepend(struct Node *node, int value) {
    struct Node *pNode = node_init(value);
    pNode->next = node;
    return pNode;
};

bool node_find(struct Node *node, int value) {
    while(node) {
        if (node->value == value) {
            return true;
        };
        node = node->next;
    };
    return false;
};

struct Node *node_insert(struct Node *node, int value, int position) {
    if(position == 0) {
        return node_prepend(node, value);
    };
    
    struct Node *newNode = node_init(value);
    
    length = node_length(node); 
    
    for(int i = 0; i < length; i++){
        if(i == position - 1) {
            newNode->next = node->next;
            node->next = newNode;
            return node;
        };
        node = node->next;
    };
};

struct Node *node_remove(struct Node *node, int position) { 
    if(position == 0) {
        struct Node *target = node->next;
        free(node);
        return target;
    };
    length = node_length(node); 
    for(int i = 0; i < length; i++){
        if(i == position - 1) {
            struct Node *target = node->next;
            node->next = target->next;
            free(target);
            return node;
        };
        node = node->next;
    };
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
    node1 = node_prepend(node1, 99); 
    node1 = node_insert(node1, 12, 1);
    node1 = node_remove(node1, 0);

    //node_find(node1, 4);
    //node_find(node1, 100);
    traverse(node1);
    node_free(node1);
    
    return 0;
};
