#include <iostream>

void recur(int i, int n)
{
	if(i <= n)
	{
		std::cout << i << std::endl;
		recur(i+1, n);
	}
}

int main(void)
{
	int n;
	std::cin >> n;
	recur(1,n);
	return 0;
}

