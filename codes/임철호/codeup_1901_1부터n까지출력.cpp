#include <stdio.h>
#include <iostream>

using namespace std;

void print(int num)
{
	if (num == 0) return;
	print(num - 1);
	cout << num << endl;
}

int main()
{
	int a; //ют╥б
	std::cin >> a;
	print(a);
	return 0;
}