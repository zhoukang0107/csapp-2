#include <stdio.h>

void multstore(long,long,long*);

int main(){
	long d;
	multstore(3,4,&d);
	printf("2*3——>%ld\n",d);
	return 0;
}

int mult2(long a, long b){
	long x = a * b;
	return x;
}

