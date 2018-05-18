#include <iostream>
#include <stdio.h>

using namespace std;

int n, cnt, queen[20]; // n = 판 넓이, cnt = 카운트, queen[i]는 x좌표가 i인 퀸의 y좌표.

void Nqueen(int x, int y)
{
	for (int i = 1; i < x; i++)
	{
		if (y == queen[i] || abs(queen[i] - y) == abs(x - i)) return;// y 값이 같거나, y와 x 의 차가 같으면 대각선
	}
	if (x == n)
	{
		if (cnt < 3) //3개만 출력하라 했음으로
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
	for (int i = 1; i <= n; i++) //열 번호 대로 나열임으로
	{
		queen[1] = i;
		Nqueen(1, i);
	}
	cout << cnt;
	return 0;
}