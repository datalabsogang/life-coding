#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int box[110][110][110]; // 상자 최고 크기

queue<int> xque, yque, zque;

int m, n, h; //x, y, z
int day = 0;


void bfs()
{
	int xx, yy, zz;

	while (!xque.empty())
	{
		xx = xque.front();
		yy = yque.front();
		zz = zque.front();


		if (xx < m && box[xx + 1][yy][zz] == 0)
		{
			xque.push(xx + 1);
			yque.push(yy);
			zque.push(zz);
			box[xx + 1][yy][zz] = box[xx][yy][zz] + 1;
		}

		if (yy < n && box[xx][yy + 1][zz] == 0)
		{
			xque.push(xx);
			yque.push(yy + 1);
			zque.push(zz);
			box[xx][yy + 1][zz] = box[xx][yy][zz] + 1;
		}

		if (zz < h && box[xx][yy][zz + 1] == 0)
		{
			xque.push(xx);
			yque.push(yy);
			zque.push(zz + 1);
			box[xx][yy][zz + 1] = box[xx][yy][zz] + 1;
		}

		if (xx > 1 && box[xx - 1][yy][zz] == 0)
		{
			xque.push(xx - 1);
			yque.push(yy);
			zque.push(zz);
			box[xx - 1][yy][zz] = box[xx][yy][zz] + 1;
		}

		if (yy > 1 && box[xx][yy - 1][zz] == 0)
		{
			xque.push(xx);
			yque.push(yy - 1);
			zque.push(zz);
			box[xx][yy - 1][zz] = box[xx][yy][zz] + 1;
		}

		if (zz > 1 && box[xx][yy][zz - 1] == 0)
		{
			xque.push(xx);
			yque.push(yy);
			zque.push(zz - 1);
			box[xx][yy][zz - 1] = box[xx][yy][zz] + 1;
		}





		xque.pop();
		yque.pop();
		zque.pop();
	}

}


int main()
{
	//상자 크기
	cin >> n >> m >> h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					xque.push(i);
					yque.push(j);
					zque.push(k);
				}
			}
		}
	}

	bfs();

	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
			{
				if (box[i][j][k] == 0)
				{
					cout << "-1" << endl;
					return 0;
				}

				if (day < box[i][j][k])
				{
					day = box[i][j][k];
				}
			}
		}
	}
	cout << day - 1 << endl;
	return 0;
}