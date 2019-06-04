#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "debug.h"

#define E 0.00001
double sqrt(double num)
{
	double down = 0;
	double up = num;
    double mid = 0.0;
	while(1)
	{
	    mid = (down + up)/2;
        if(fabs(mid*mid - num) <= E)
		{
			return mid;
		}

		if ((mid*mid - num) > E)
		{
			up = mid;
		}
		else
		{
			down = mid;
		}
 	}

	return 0;
}
 
//formula:
int resursion_bsearch(int a[],int left,int right,int target) {
	if(left > right) {
		return -1;
	}
	int mid = left + ((right-left) >> 1);
	
	if(target == a[mid]) {
		return mid;
	} else if(target > a[mid]) {
		resursion_bsearch(a,mid+1,right,target);
	} else {
		resursion_bsearch(a,left,mid-1,target);
	}
}

int rbsearch(int a[],int size,int target) {
	return resursion_bsearch(a,0,size-1,target);
}

int simple_bsearch(int a[],int size,int target) {
	int right = size-1;
	int left = 0;

	while(left <= right) {
		//int mid = (right+left)/2;  if right and left is too big, may overflow
		int mid = left + ((right-left) >> 1);
		if(target == a[mid]) {
			return mid;
		}
		else if(target > a[mid]) {
			left = mid+1;
		} else {
			right = mid-1;
		}
	}

	return -1;
}
#if BINARY_SEARCH
int main()
{
	int size = 8;
	int target = 5;
	int a[size] = {1,2,3,4,5,6,7,8};

	printf("find %d: pos=%d \n",target,simple_bsearch(a,size,2));
	printf("find %d: pos=%d \n",target,rbsearch(a,size,8));
	printf("sqrt 6: %lf\n",sqrt(6));
	return 0;
}
#endif
