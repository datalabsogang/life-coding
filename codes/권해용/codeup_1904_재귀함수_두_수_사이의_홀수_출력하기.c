#include <stdio.h>

void recur(int a, int b)
{
	if (a > b)
	{
		return;
	}

	if (a % 2 == 0)
    recur(a+1,b);
  else if(a == b)
	{
		printf("%d \n",a);
		return;
	}
	else 
	{
		printf("%d ",a);
    recur(a+2,b);
	}
}

void recur2(int a, int b)
{
	if (a > b)
		return;
	printf("%d ",a);
	recur2(a+2,b);
}

int main(void)
{
	int a, b;
	scanf("%d",&a);
	scanf("%d",&b);

	// method 1
  //recur(a,b);

  // method 2
	if (a % 2 == 0)
		a = a + 1;

  recur2(a,b);
	printf("\n");

	return 0;
}

