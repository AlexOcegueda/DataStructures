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

struct Tree *tree_init(int value) {
	struct Tree *t = malloc(sizeof(struct Tree));
	t->root = node_init(value);
	return t;
};

void tree_insert(struct Tree *t, int value) {
		
	struct Node *current = t->root;
	if (current->left == NULL) {
		current->left = node_init(value);
        return;
	}else if (current->right == NULL) {
		current->right = node_init(value);
		return;
	};

    while (current) {
		if (current == NULL) {
			current = node_init(value);
			return;
		};
		current = current->left;
	};
};

void traverse(struct Node *node) {
	if (node == NULL) {
		return;
	};
	printf("%d\n", node->value);
	traverse(node->right);
	traverse(node->left);
	return;
};
    
int main() {
	struct Tree *t = tree_init(0);
	tree_insert(t, 100);
	tree_insert(t, 20);
	tree_insert(t, 30);
	tree_insert(t, 40);
	tree_insert(t, 60);
	traverse(t->root);
	return 0;
};
