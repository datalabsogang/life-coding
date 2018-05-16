#include <stdio.h>
#include <iostream>
using namespace std;
void print(int num, int num2)
{
	if (num > num2) return;
	if (num & 1)
		cout << num << " ";
	num = num + 1;
	print(num, num2);
}

int main()
{
	int a; int b;
	cin >> a;
	cin >> b;
	print(a, b);
	return 0;
}