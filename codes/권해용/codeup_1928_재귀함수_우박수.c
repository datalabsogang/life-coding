#include <stdio.h>

void recur(int n)
{
	printf("%d\n",n);
	if(n==1)
		return;
	else if(n%2 == 1)
		recur(3*n+1);
	else
		recur(n/2);
}


int main(void)
{
	int n;
	scanf("%d",&n);
	recur(n);
	return 0;
}
