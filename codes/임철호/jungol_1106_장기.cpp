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
	// 진행할 방향들
	int dy[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int dx[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
	bool sw = false;

	// 큐가 빌때까지 탐색
	while (!que.empty()) {
		// 큐의 제일 앞에 있는 것을 포인트로 꺼내옴
		p = que.front();
		que.pop();
		// 각 방향 한번씩 탐색
		for (int i = 0; i < 8; i++) {
			// 앞으로 갈 새 포인트 생성
			XY next = newXY(p.y + dy[i], p.x + dx[i]);

			// 범위 안벗어 났을 경우
			if (next.y >= 0 && next.y < height && next.x >= 0 && next.x < width) {
				if (map[next.y][next.x] == 0) {
					// 앞으로 갈 방향에 지금 값 + 1
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