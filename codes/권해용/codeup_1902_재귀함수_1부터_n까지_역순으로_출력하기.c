#include <stdio.h>

void recur(int i)
{
	if (i > 0)
	{ 
		printf("%d\n",i);
	  recur(i-1);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
  recur(n);
  return 0;
}
