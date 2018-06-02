#include <stdio.h>

void recur(int i, int n)
{
	if (i <= n)
	{ 
		printf("%d\n",i);
	  recur(i+1, n);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
  recur(1, n);
  return 0;
}