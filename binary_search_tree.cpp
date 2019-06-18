#include "debug.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

typedef struct _node {
	int data;
	struct _node *left;
	struct _node *right;
} Tree,TreeNode;

bool insert_node(Tree *root,TreeNode *node) {
	if(root == NULL) {
		return false;
	}
	TreeNode *p = root;
	while(p != NULL) {
		if(node->data > p->data) {
			if(p->right == NULL) {
				p->right = node;
				return true;
			}
			p = p->right;
		}
			
		if(node->data < p->data) {
			if(p->left == NULL) {
				p->left = node;
				return true;
			}
			p = p->left;
		}
	}
	return false;
}

TreeNode *search_node(TreeNode *root,int data) {
	TreeNode *p = root;
	while(p != NULL) {
		if(data > p->data) {
			p = p->right;
		}
		if(data < p->data) {
			p = p->left;
		}
		if(data == p->data) {
			return p;
		}
	}
	return NULL;
}

void remove_node(TreeNode *node) {
	
}

void _inOrder(TreeNode *root) {
	if(root == NULL)
		return;
	_inOrder(root->left);
	printf(" %d\n",root->data);
	_inOrder(root->right);
}
#if BINARY_SEARCH_TREE
int main() {
	printf("binary_search_tree:\n");
	int values[10] = {2,3,4,6,8,9,-2,-4,10,22};
	Tree *root = (TreeNode *) malloc(sizeof(TreeNode));
	root->data = values[0];
	root->left = NULL;
	root->right= NULL;
	
	for(int i=1;i<9;i++) {
		TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
		node->data = values[i];
		node->left = NULL;
		node->right= NULL;
		insert_node(root,node);
	}
	_inOrder(root);
	TreeNode *ss = search_node(root,8);
	if(ss != NULL)
		printf("find %d\n",ss->data);
}
#endif
