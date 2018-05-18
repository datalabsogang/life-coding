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

	cin >> ROW >> COL; //7 , 8 �̸� 8�� 7��

	for (i = 0; i < ROW; i++)  //�����޴´� �ప��ŭ COL��
	{
		char *tmp = (char *)malloc(sizeof(char)*ROW);

		cin >> tmp;
		int cnt = 0;
		while (tmp[cnt] != NULL)
		{
			if (tmp[cnt] == 'W') //�ٴ��̸�
				map[i][cnt] = 0;
			else if (tmp[cnt] == 'L')//�����̸�
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
			POSITION[head].Y = j;  //������ �ʱ�ȭ
			int temp = 0;
			while (1)  //bfs����
			{
				if (head == tail)break;
				for (int dir = 0; dir < 4; dir++)
				{
					int tmpX = POSITION[head].X + Dx[dir];
					int tmpY = POSITION[head].Y + Dy[dir];  //�����¿�
					if (tmpX >= 0 && tmpX < ROW&&tmpY >= 0 && tmpY < COL)
					{
						temp = chk[POSITION[head].X][POSITION[head].Y] + 1;  //�̵��Ҷ����� 1������
						if (map[tmpX][tmpY] == 1 && mini[tmpX][tmpY]>temp) //�����϶� �湮 �ǵ��ư��� ����
						{
							chk[tmpX][tmpY] = temp; //���������� �Ÿ� 0���� �����ؼ� temp���� ����
							mini[tmpX][tmpY] = temp; //���������� �Ÿ� 0x0fffff �����ؼ� �ִܰŸ��� ����
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

			//�ִܰŸ��� �̵��ؾߵ�
			for (int r1 = 0; r1 < ROW; r1++)
				for (int r2 = 0; r2 < COL; r2++)
				{
					chk[r1][r2] = 0;   //���������� �ʱ�ȭ �Ʒ��� ��������
					mini[r1][r2] = 0x0ffffff;
				}
		}
	cout << maxi;
}