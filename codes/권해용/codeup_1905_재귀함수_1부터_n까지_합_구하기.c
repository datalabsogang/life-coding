#include <stdio.h>

void recur(int n, int* pSum)
{
	if(n == 0)
		return;
	else
	{
		*pSum = *pSum + n;
		recur(n-1, pSum);
	}
}

int recur2(int n)
{
	if (n == 0)
		return 0;

	return n + recur2(n-1);
}

int main(void)
{
	int n;
	int sum = 0;
	scanf("%d",&n);
	//recur(n, &sum);
	//printf("%d\n",sum);
	printf("%d\n",recur2(n));
	return 0;
}
