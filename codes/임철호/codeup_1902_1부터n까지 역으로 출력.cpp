#include <stdio.h>
#include <iostream>

using namespace std;

void print(int num)
{
	if (num == 0) return;
	cout << num << endl;
	print(num - 1);

}

int main()
{
	int a; //�Է�
	std::cin >> a;
	print(a);
	return 0;
}