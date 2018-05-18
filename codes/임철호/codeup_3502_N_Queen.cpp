#include <iostream>
#include <stdio.h>

using namespace std;

int n, cnt, queen[20]; // n = �� ����, cnt = ī��Ʈ, queen[i]�� x��ǥ�� i�� ���� y��ǥ.

void Nqueen(int x, int y)
{
	for (int i = 1; i < x; i++)
	{
		if (y == queen[i] || abs(queen[i] - y) == abs(x - i)) return;// y ���� ���ų�, y�� x �� ���� ������ �밢��
	}
	if (x == n)
	{
		if (cnt < 3) //3���� ����϶� ��������
		{
			for (int i = 1; i <= n; i++)
			{
				cout << queen[i] << " ";
			}
			cout << "" << endl;
		}
		cnt++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		queen[x + 1] = i;
		Nqueen(x + 1, i);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) //�� ��ȣ ��� ����������
	{
		queen[1] = i;
		Nqueen(1, i);
	}
	cout << cnt;
	return 0;
}