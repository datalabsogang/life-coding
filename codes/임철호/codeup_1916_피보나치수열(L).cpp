#include <stdio.h> 
#include <iostream>

using namespace std;

int arry[200];
int print(int num)
{
	if (arry[num])
		return arry[num];
	if (num == 1 || num == 2) return 1;
	return arry[num] = (print(num - 1) + print(num - 2)) % 10009;
}

int main()
{
	int a;
	cin >> a;
	cout << print(a);
	return 0;
}