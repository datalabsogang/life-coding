#include <iostream>
#include <queue>

using namespace std;

struct XY {
	int x, y;
};

int width, height, nX, nY, pX, pY;
int map[103][103] = { 0, };
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
	int dy[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int dx[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
	bool sw = false;

	// ť�� �������� Ž��
	while (!que.empty()) {
		// ť�� ���� �տ� �ִ� ���� ����Ʈ�� ������
		p = que.front();
		que.pop();
		// �� ���� �ѹ��� Ž��
		for (int i = 0; i < 8; i++) {
			// ������ �� �� ����Ʈ ����
			XY next = newXY(p.y + dy[i], p.x + dx[i]);

			// ���� �ȹ��� ���� ���
			if (next.y >= 0 && next.y < height && next.x >= 0 && next.x < width) {
				if (map[next.y][next.x] == 0) {
					// ������ �� ���⿡ ���� �� + 1
					map[next.y][next.x] = map[p.y][p.x] + 1;
					que.push(next);

					if (next.y == pY && next.x == pX) {
						map[pY][pX] = map[p.y][p.x] + 1;
						sw = true;
						break;
					}

				}
			}
		}

		if (sw) {
			break;
		}
	}

	return map[pY][pX];
}

int main()
{
	cin >> width >> height >> nX >> nY >> pX >> pY;

	que.push(newXY(nY, nX));

	cout << bfs();
	return 0;
}