#include<stdio.h>

void recur(int i, int n, int* memory)
{
	//printf("%d, %d, %d\n", i, n, memory[i]);
	if (n == 1)
		return;
	else if (n == 2)
		return;
	else if (i > 2)
	{
		memory[i] = (memory[i-1] + memory[i-2])%10009;
	  //printf("memory[i]: %d\n", memory[i]);
	}
	if (i == n)
		return;
	else
		recur(i+1, n, memory);
}

int main(void)
{
	int n;
	int memory[201] = {0};
	memory[1] = 1;
	memory[2] = 1;

	scanf("%d",&n);
	recur(1, n, memory);
  printf("%d\n",memory[n]);
	return 0;
}
