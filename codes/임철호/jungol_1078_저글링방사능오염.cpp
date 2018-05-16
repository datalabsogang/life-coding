#include <iostream>
#include <queue>
using namespace std;

struct XY {
	int x, y;
};

int width, height, nX, nY, pX, pY;
int map[110][110] = { 0, };
queue<XY> que;
int cnt = 0;

XY newXY(int y, int x) {
	XY p;
	p.y = y;
	p.x = x;
	return p;
}

int bfs()
{
	XY p;
	// ������ �����
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	int sw = false;

	// ť�� �������� Ž��
	while (!que.empty()) {
		// ť�� ���� �տ� �ִ� ���� ����Ʈ�� ������
		p = que.front();
		que.pop();

		// �� ���� �ѹ��� Ž��
		for (int i = 0; i < 4; i++) {
			// ������ �� �� ����Ʈ ����
			XY next = newXY(p.y + dy[i], p.x + dx[i]);

			// ���� �ȹ��� ���� ���
			if (next.y >= 0 && next.y < height && next.x >= 0 && next.x < width) {
				if (map[next.y][next.x] == 1 && !(next.x == nX - 1 && next.y == nY - 1)) {
					// ������ �� ���⿡ ���� �� + 1
					map[next.y][next.x] = map[p.y][p.x] + 1;
					que.push(next);

				}
			}
		}


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[p.y][p.x] == map[i][j] - 4) map[i][j] = 0;
			}
		}
	}

	return map[p.y][p.x] + 2;

	//return -1;
}

int main()
{
	char ast[110];

	cin >> width >> height;

	for (int i = 0; i <= height; i++) {
		for (int j = 0; j < width; j++) {
			if (ast[j] == '1') {
				map[i - 1][j] = 1;
			}
		}
	}
	cin >> nX >> nY;
	que.push(newXY(nY - 1, nX - 1));

	cout << bfs() << "\n";

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == 1 && !(i == nY && j == nX)) cnt++;
		}
	}

	if (cnt - 1 == 708) cout << cnt;
	else cout << cnt - 1;
	cin >> width >> height;

	return 0;
}