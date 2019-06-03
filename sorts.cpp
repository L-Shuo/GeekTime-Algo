#include <iostream>
#include <malloc.h>
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
				a[j+1] = a[j];  //∫Û“∆ 
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


//formula: merge_sort(p,r) = merge(merge_sort(p,q),merge_sort(q+1,r);
//termination: p>=r
void merge(int a[],int p,int q,int r) {
	//merge two sorted array.
	int *temp = (int *)malloc((r-p+1) * sizeof(int));
	int i,j,k;
	if(!temp)
		return;
	for(i=p,j=q+1,k=0;i<=q&&j<=r;) {
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	if(i == q+1) { //something left
		for(;j<=r;) {
			temp[k++] = a[j++];
		}
	} else {
		for(;i<=q;) {
			temp[k++] = a[i++];
		}
	}
	memcpy(a+p,temp,(r-p+1) * sizeof(int));
	free(temp);
}

void __merge_sort(int a[],int p,int r) {
	if (p>=r)
		return;
	int q = (p+r)/2;
	__merge_sort(a,p,q);
	__merge_sort(a,q+1,r);
	merge(a,p,q,r);
}
void merge_sort(int a[],int size) {
	__merge_sort(a, 0, size-1);
}

//formula: quick_sort=quick_sort(p...q-1)+quick_sort(q+1,r)
//termination: p>=r
int partition(int a[], int p, int r) {
	int i=p;
	int temp;
	int pivot = a[r];
	for(int j=p;j<r;j++) {
		if(a[j] < pivot) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
	}
	temp = a[i];
	a[i] = a[r];
	a[r] = temp;
	return i;
}

void __quick_sort(int a[],int p,int r) {
	if(p >=r )
		return;
	int q = partition(a,p,r);
	__quick_sort(a,p,q-1);
	__quick_sort(a,q+1,r);
}
void quick_sort(int a[],int size) {
	__quick_sort(a,0,size-1);
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
	
	printf("merge sort: ");
	int d[size] = {4,8,6,1,1,3};
	merge_sort(d,size);
	dump_array(d,size);
	
	printf("quick sort: ");
	int e[size] = {4,8,6,1,1,3};
	quick_sort(e,size);
	dump_array(e,size);
	return 0;
}
#endif
