#include<stdio.h>
#include<stdlib.h>

struct Tree {
		struct Node *root;
};

struct Node {
		int value;
		struct Node *right;
		struct Node *left;
};

struct Node *node_init(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->right = NULL;
		node->left = NULL;

    return node;
};

struct Tree *tree_init() {
		struct Tree *t = malloc(sizeof(struct Tree));
		struct Node *right = node_init(0);
		struct Node *left = node_init(0);
		
		t->root->right = right;
		t->root->left = left;
		
		return t;
};

 

int main() {
		struct Tree *t = tree_init();
		printf("%d\n", t->root->right->value);
		return 0;
};
