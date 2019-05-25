#include "debug.h"
#include <iostream>

int depth = 0;
int fib(int n) {
	++depth;
	//printf("depth:%d\n",depth);
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	return fib(n-1) + fib(n-2);
}
#if RECURSION
int main() {
	printf("%d\n",fib(30));
}
#endif

