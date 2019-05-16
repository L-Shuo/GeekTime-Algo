#include <iostream>

struct list_node {
	struct list_node *next;
	int val;
};

struct list_head {
	struct list_node *head;
};

bool is_empty(struct list_head *head) {
	return head->head == NULL;
}

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

void reverse(struct list_head *head) {
	struct list_node *pre = head->head;
	struct list_node *cur = pre->next;

	while(cur != NULL) {
		struct list_node *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head->head->next = NULL;
	head->head = pre;
}

bool is_cyclic(struct list_head *head) {

}

void del_backwards(struct list_head  *head, int n) {

}

void merge_sorted_list(struct list_head *h1, struct list_head *h2) {

}

struct list_node *find_middle(struct list_head *head) {
	struct list_node *fast = head->head;
	struct list_node *slow = head->head;

	if(!head->head)
		return NULL;

	while (fast && fast->next) {
		//if (!fast || !fast->next)
		//	return slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
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
	//printf("%ld\n",(&head)->head);
	dump(&head);
	//insert_head(&head,&nodes[3]);
	//printf("%ld\n",(&head)->head);
	dump(&head);
	//insert_head(&head,&nodes[2]);
	//printf("%ld\n",(&head)->head);
	dump(&head);
	insert_head(&head,&nodes[1]);
	insert_head(&head,&nodes[8]);
	insert_head(&head,&nodes[7]);
	insert_head(&head,&nodes[5]);
	insert_head(&head,&nodes[4]);
	insert_head(&head,&nodes[9]);
	//printf("%ld\n",(&head)->head);
	dump(&head);
	
	struct list_node *middle = find_middle(&head);
	printf("middle=%d\n",middle->val);
	
	
	
	del_head(&head);
	dump(&head);
	
	printf("reverse: ");
	reverse(&head);
	dump(&head);
	
	return 0;
}
