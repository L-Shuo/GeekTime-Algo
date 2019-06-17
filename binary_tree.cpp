#include "debug.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;
#define MAX_TREE_NODES (1<<8)
#define SIZE  3
typedef struct _node {
	int data;
	struct _node *lf;
	struct _node *rt;
} Tree, TreeNode;

int a[SIZE] = {2,3,-1};//,5,6,8,10,0,7,22};
int index = 0;
void create_binary_tree(Tree **root) {
	/*
	if(index > SIZE-1) {
		*root = NULL;
	} else {
		if(*root == NULL) {
			return;
		}
		*root = (TreeNode *)malloc(sizeof(TreeNode));
		(*root)->data = a[index++];
		//printf("%d\n",(*root)->data);
		create_binary_tree(&((*root)->lf));
		create_binary_tree(&((*root)->rt));
	}
	*/
	int a = 0;
	printf("\r\n输入节点数值((当输入为100时，当前节点创建完成))):");
	scanf("%d",&a);


	if (a == 100)
	{
		*root = NULL;
	}
	else
	{
		*root = (TreeNode *)malloc(sizeof(TreeNode));
		if (*root == NULL)
		{
			return;
		}

		(*root)->data = a;
		printf("\r\n create %d 的左孩子:",a);
		create_binary_tree(&((*root)->lf));
		printf("\r\n create %d 的右孩子:",a);
		create_binary_tree(&((*root)->rt));
	}

	return ;
}

void levelOrder(Tree *root) {
	queue<TreeNode*> q;
	//TreeNode *node = root;
	q.push(root);
	while(!q.empty()) {
		TreeNode *node = q.front();
		printf(" %d",node->data);
		if(node->lf)
			q.push(node->lf);
		if(node->rt)
			q.push(node->rt);
		q.pop();
	} 
}

void preOrder(Tree *root) {
	if(root == NULL) {
		return;
	}
	printf(" %d",root->data);
	preOrder(root->lf);
	preOrder(root->rt);
	return;
}

void inOrder(Tree *root) {
	if(root == NULL) {
		return;
	}
	inOrder(root->lf);
	printf(" %d",root->data);
	inOrder(root->rt);
	return;
}

void postOrder(Tree *root) {
	if(root == NULL) {
		return;
	}
	postOrder(root->lf);
	postOrder(root->rt);
	printf(" %d",root->data);
	return;
}

void destroyTree(Tree *root) {
	if(root == NULL) {
		return;
	}
	destroyTree(root->lf);
	destroyTree(root->rt);
	free(root);
}

#if BINARY_TREE
int main() {
	printf("Create binary tree:\n");
	Tree *root;
	create_binary_tree(&root);
	printf("\n preOrder:\n");
	preOrder(root);
	printf("\n inOrder:\n");
	inOrder(root);
	printf("\n postOrder:\n");
	postOrder(root);
	printf("\n levelOrder:\n");
	levelOrder(root);
}
#endif
