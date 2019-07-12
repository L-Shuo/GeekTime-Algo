#include <iostream>
#include "debug.h"

void printPermutation(int data[],int n,int k) {
	if( k == 1) {
		for(int i=0;i<n;i++) {
			printf("%d ",data[i]);
		}
		printf("\n");
	}
	
	for (int i=0;i<k;i++) {
		int tmp = data[i];
		data[i] = data[k-1];
		data[k-1] = tmp;
		
		printPermutation(data,n,k-1);
		
		tmp = data[i];
		data[i] = data[k-1];
		data[k-1] = tmp;
	}
}
#if PPP
int main() {
	printf("print permutation:\n");
	int nums[3] = {1,2,3};
	printPermutation(nums,3,3);
}
#endif
