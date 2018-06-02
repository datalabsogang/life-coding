#include <stdio.h>

void horiStar(int i, int n)
{
	if(i == n)
	{
		printf("\n");
		return;
	}
	printf("*");
	horiStar(i+1,n);
}

void recur(int i, int n)
{
	if(i == n)
	{
		return;
	}
	else
	{
    horiStar(0, i+1);
    recur(i+1, n);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
  recur(0, n);
	return 0;
}

