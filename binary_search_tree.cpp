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
		else if(data < p->data) {
			p = p->left;
		}
		else {
			printf("%ld\n",p);
			return p;
		}
	}
	return NULL;
}

void remove_node(Tree *root,TreeNode *node) {
	TreeNode *p = root;
	TreeNode *pp = NULL; //parent
	while( p!= NULL && p->data != node->data) {
		pp = p;
		if(node->data > p->data) {
			p = p->right;
		}
		else {
			p = p->left;
		}
	}
	if( p == NULL) {
		printf("cannot find target!");
		return;
	}
	
	if(p->left != NULL && p->right != NULL) {
		//删除的节点有两个子节点,需要找到右子树中最小节点替换该节点
		//printf("----1----\n");
		TreeNode *minP = p->right;
		TreeNode *minPP = p; //minP's parent
		while( minP->left != NULL) {
			minPP = minP;
			minP = minP->left;
		}
		p->data = minP->data;
		p = minP; //下面代码复用，用来删除minP 
		pp = minPP;
	}
	TreeNode *child;
	if(p->left != NULL) {
		child = p->left;
	}
	else if(p->right != NULL) {
		child = p->right;
	}
	else
		child = NULL;
	if( pp == NULL) {//删除的是root节点 
		root = child;
		free(root);
	}
	else if(pp->left == p) {
		pp->left = child;
	}
	else {
		pp->right = child;
	}
	free(p);
}

void _inOrder(TreeNode *root) {
	if(root == NULL)
		return;
	_inOrder(root->left);
	printf("%ld %d\n",root,root->data);
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

	for(int i=1;i<10;i++) {
		TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
		node->data = values[i];
		node->left = NULL;
		node->right= NULL;
		insert_node(root,node);
	}
	_inOrder(root);
	TreeNode *s1 = search_node(root,22);
	if(s1 != NULL) {
		printf("##find %d\n",s1->data);
		remove_node(root,s1);
		_inOrder(root);
	}
	
	TreeNode *s2 = search_node(root,2);
	if(s2 != NULL) {
		printf("##find %d\n",s2->data);
		remove_node(root,s2);
		_inOrder(root);
	}
}
#endif
