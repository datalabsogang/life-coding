#include <stdio.h> 
#include <iostream>

using namespace std;

void pStar(int n)
{
	if (n == 0)return;
	pStar(n - 1);
	printf("*");
}

void print(int num)
{
	if (num == 0) return;
	print(num - 1);
	pStar(num);
	printf("\n");
}


int main()
{
	int num;
	cin >> num;
	print(num);

	return 0;
}