#include <stdio.h>
#include <iostream>
using namespace std;

int print(int num)
{
	if (num == 1 || num == 2) return 1;
	return print(num - 1) + print(num - 2);

}

int main()
{
	int a;
	cin >> a;
	cout << print(a);
	return 0;
}