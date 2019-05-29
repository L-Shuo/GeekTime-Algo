#include <iostream>
#include "debug.h"

void bubble_sort(int a[],int size) {
	if(size <= 1)
		return;
	for(int i=0;i<size;i++) {
		bool __switch = false; //optimize, if no switch in the sub sequence,we quit the job.
		for(int j=0;j<size-i-1;j++) {
			if(a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				__switch = true;
			}
		}
		if(!__switch)
			break;
	}
}

void insert_sort(int a[],int size) {
	if(size < 1)
		return;
	for(int i=1;i<size;i++) {
		int value = a[i];
		int j = i-1;
		for(;j>=0;j--) {
			if(a[j] > value) {
				a[j+1] = a[j];  //���� 
			} else {
				break;
			}
		}
		a[j+1] = value; //insert
	} 
}

void select_sort(int a[], int size) {
	int min;
	for(int i=0;i<size;i++) {
		int min_pos = i;
		for(int j=i+1;j<size;j++) {
			if(a[j] < a[min_pos]) {
				min_pos = j;  //find the min pos
			}
		}
		//swap them;
		min = a[min_pos];
		a[min_pos] = a[i];
		a[i] = min;
	}
}

void dump_array(int a[],int size) {
	if(size < 0) {
		return;
	}
	int i=0;
	while(i<size) {
		printf("%d ",a[i++]);
	}
	printf("\n");
}
#if SORTS
int main() {
	int size = 6;
	printf("bubble sorts: ");
	int a[size] = {4,5,1,2,3,6};
	bubble_sort(a,size);
	dump_array(a,size);
	
	printf("insert sorts: ");
	int b[size] = {4,5,6,3,2,1};
	insert_sort(b,size);
	dump_array(b,size);
	
	printf("selection sort: ");
	int c[size] = {4,8,6,1,2,3};
	select_sort(c,size);
	dump_array(c,size);
	return 0;
}
#endif