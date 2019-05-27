#include <iostream>
#include "debug.h"

void bubble_sort(int a[],int size) {
	if(size <= 1)
		return;
	for(int i=0;i<size;i++) {
		bool __switch = false; //optimize, if no switch in the sub sequence,we quit the job.
		for(int j=i;j<size-i;j++) {
			if(a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				__switch = true;
			}
		}
		if(!__switch)
			break;
	}
}

void dump_array(int a[],int size) {
	if(size < 0) {
		return;
	}
	while(size--) {
		printf("%d ",a[size]);
	}
	printf("\n");
}
#if SORTS
int main() {
	printf("bubble sorts: ");
	int size = 6;
	int a[size] = {4,5,6,3,2,1};
	bubble_sort(a,size);
	dump_array(a,size); 
	return 0;
}
#endif
