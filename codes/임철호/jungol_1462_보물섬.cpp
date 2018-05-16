#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int ROW, COL;
int map[51][51];
int chk[51][51];
int mini[51][51];
int maxi = 0;

typedef struct {
	int X;
	int Y;
}_pos;

_pos POSITION[10000];
int Dx[] = { -1,1,0,0 };
int Dy[] = { 0,0,-1,1 };
char temp = 0;

int main(void)
{
	int i, j;

	cin >> ROW >> COL; //7 , 8 이면 8행 7열

	for (i = 0; i < ROW; i++)  //값을받는다 행값만큼 COL개
	{
		char *tmp = (char *)malloc(sizeof(char)*ROW);

		cin >> tmp;
		int cnt = 0;
		while (tmp[cnt] != NULL)
		{
			if (tmp[cnt] == 'W') //바다이면
				map[i][cnt] = 0;
			else if (tmp[cnt] == 'L')//육지이면
				map[i][cnt] = 1;
			cnt++;
		}
	}
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++) {
			chk[i][j] = 0;
			mini[i][j] = 0x0fffffff;
		}
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
		{
			if (map[i][j] == 0)
				continue;
			int head = 0, tail = 1;
			POSITION[head].X = i;
			POSITION[head].Y = j;  //시작점 초기화
			int temp = 0;
			while (1)  //bfs시작
			{
				if (head == tail)break;
				for (int dir = 0; dir < 4; dir++)
				{
					int tmpX = POSITION[head].X + Dx[dir];
					int tmpY = POSITION[head].Y + Dy[dir];  //상하좌우
					if (tmpX >= 0 && tmpX < ROW&&tmpY >= 0 && tmpY < COL)
					{
						temp = chk[POSITION[head].X][POSITION[head].Y] + 1;  //이동할때마다 1씩증가
						if (map[tmpX][tmpY] == 1 && mini[tmpX][tmpY]>temp) //육지일때 방문 되돌아갈수 없음
						{
							chk[tmpX][tmpY] = temp; //시작점부터 거리 0부터 시작해서 temp값을 증가
							mini[tmpX][tmpY] = temp; //시작점부터 거리 0x0fffff 시작해서 최단거리를 구함
							POSITION[tail].X = tmpX;
							POSITION[tail].Y = tmpY;
							tail++;
						}
					}
				}
				head++;
			}
			for (int a = 0; a < ROW; a++)
			{
				for (int b = 0; b < COL; b++)
					if (maxi < chk[a][b])
						maxi = chk[a][b];
			}

			//최단거리로 이동해야됨
			for (int r1 = 0; r1 < ROW; r1++)
				for (int r2 = 0; r2 < COL; r2++)
				{
					chk[r1][r2] = 0;   //시작점부터 초기화 아래도 마찬가지
					mini[r1][r2] = 0x0ffffff;
				}
		}
	cout << maxi;
}