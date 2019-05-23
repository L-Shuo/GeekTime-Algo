#include <iostream>
#include <string>
#include "debug.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Array {
	int size;
	int used;
	int *base;
};

//Sort the arrays from little to big when inserted
int insert(struct Array *array, int value) {
	int idx;
	if(array->used >= array->size)
		return -1;
	for(idx = 0;idx < array->used;idx++) {
		if(array->base[idx] > value)
			break;
	}
	
	if(idx < array->used) {
		memmove(&array->base[idx+1],&array->base[idx],(array->used-idx)*sizeof(int));
	}
	
	array->base[idx] = value;
	array->used++;
	return idx;
}

//search
int search(struct Array *array, int value) {
	for(int idx=0;idx < array->used; idx++) {
		if(array->base[idx] == value)
			return idx;
		if(array->base[idx] > value) //array is sorted,if index 0 is bigger than pattern,no need to continue. 
			return -1;
	}
	
	return -1;
}

//delete
int m_delete(struct Array *array, int idx) {
	if(idx <0 || idx >= array->used)
		return -1;

	memmove(&array->base[idx],&array->base[idx+1],(array->used-idx-1)*sizeof(int));
	array->used--;
	return 0;
}

//dump
void dump(struct Array *array) {
	for(int idx=0;idx<array->used;idx++) {
		printf("%d ",array->base[idx]);
	}
	printf("used:%d\n",array->used);
}

#if STACK_MAIN
int main(int argc, char** argv) {
	
	struct Array m_array = { 10,0,NULL};
	m_array.base = (int *)malloc(m_array.size);
	
	if(m_array.base == NULL) {
		exit(-1);
	}
	
	insert(&m_array,1);
	insert(&m_array,3);
	insert(&m_array,2);
	dump(&m_array);
	
	m_delete(&m_array,2);
	dump(&m_array);
	
	printf("search 1:  %d\n",search(&m_array,1));
	printf("search 10: %d\n",search(&m_array,10));
	return 0;
}
#endif
