#include <iostream>

struct list_node {
	struct list_node *next;
	int val;
};

struct list_head {
	struct list_node *head;
};

void insert(struct list_node **prev, struct list_node *node) {
	if(!prev) {
		return;
	}
	if(*prev) {
		node->next = *prev;
	}
	*prev = node;
}

void insert_head(struct list_head *head,struct list_node *node) {
	insert(&head->head,node);
}

struct list_node *del(struct list_node **prev) {
	struct list_node *tmp;
	if(!prev)
		return NULL;
	
	tmp = *prev;
	*prev = (*prev)->next;
	tmp->next = NULL;
	
	return tmp;
}

void del_head(struct list_head *head) {
	del(&head->head);
}

void dump(struct list_head *head) {
	struct list_node *tmp = head->head;
	while(tmp) {
		printf("%d ",tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(int argc, char** argv) {
	struct list_head head = {NULL};
	struct list_node nodes[10];
	for(int i=0;i<10;i++) {
		nodes[i].val = i;
		nodes[i].next = NULL;
	}
	
	insert_head(&head,&nodes[6]);
	printf("%ld\n",(&head)->head);
	dump(&head);
	insert_head(&head,&nodes[3]);
	printf("%ld\n",(&head)->head);
	dump(&head);
	insert_head(&head,&nodes[2]);
	printf("%ld\n",(&head)->head);
	dump(&head);
	insert_head(&head,&nodes[5]);
	printf("%ld\n",(&head)->head);
	dump(&head);
	
	del_head(&head);
	dump(&head);
	return 0;
}
