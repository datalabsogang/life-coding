#include <iostream>

int arry[8][8] = { 0, };
int vistied[8][8] = { 0, }; //¹æ¹® Å½»ö
int m, n, number = 0, stack = 0;

using namespace std;

void crash(int x, int y)
{

	int v = arry[x][y];

	if (x < 0 || y < 0 || x >7 || y >7)
		return;

	if (vistied[x][y] == 1) return;

	if (vistied[x][y] == 0)
		number++;
	else
		return;

	vistied[x][y] = 1;


	if (!vistied[x][y + 1] && arry[x][y + 1] == v)
		crash(x, y + 1);
	if (!vistied[x + 1][y] && arry[x + 1][y] == v)
		crash(x + 1, y);
	if (!vistied[x][y - 1] && arry[x][y - 1] == v)
		crash(x, y - 1);
	if (!vistied[x - 1][y] && arry[x - 1][y] == v)
		crash(x - 1, y);

}

int main()
{
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cin >> arry[i][j];
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			number = 0;

			crash(j, i);

			if (number >= 3)
				stack++;
		}
	}

	cout << stack << endl;
}