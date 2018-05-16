#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int n, m, k;

int sx, sy, ex, ey;


struct bus
{
	int d, x1, y1, x2, y2;

	bus() {}

	bus(int _d, int _x1, int _y1, int _x2, int _y2) :d(_d), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

	~bus() {}
};

vector<bus> v;
vector<bool> isEnd;

bool adj(int i, int j)
{
	if (i == j)  //같으면 비교에 의미가 없기에 리턴
		return 0;

	bool iv = v[i].x1 == v[i].x2 ? 1 : 0;
	bool jv = v[j].x1 == v[j].x2 ? 1 : 0;

	if (iv == 1 && jv == 1) //x축이 같은 것 끼리 찾는다.
	{
		if (v[i].x1 != v[j].x1)  // i의 x1과 j의 x1이 다르면 false.
			return 0;
		if ((v[i].y1 <= v[j].y1 && v[j].y2 <= v[i].y2) ||
			(v[j].y1 <= v[i].y1 && v[i].y2 <= v[j].y2) ||
			(v[j].y1 <= v[i].y2 && v[i].y1 <= v[j].y1 && v[i].y2 <= v[j].y2) ||
			(v[i].y1 <= v[j].y2 && v[j].y1 <= v[i].y1 && v[j].y2 <= v[i].y2))
		{
			return 1; //y축이 이어지면 true
		}
	}
	else if (iv == 0 && jv == 0)
	{
		if (v[i].y1 != v[j].y1)
			return 0;
		if ((v[i].x1 <= v[j].x1 && v[j].x2 <= v[i].x2) ||
			(v[j].x1 <= v[i].x1 && v[i].x2 <= v[j].x2) ||
			(v[j].x1 <= v[i].x2 && v[i].x1 <= v[j].x1 && v[i].x2 <= v[j].x2) ||
			(v[i].x1 <= v[j].x2 && v[j].x1 <= v[i].x1 && v[j].x2 <= v[i].x2)) {
			return 1;
		}
	}
	else if (iv == 1 && jv == 0)
	{
		if ((v[i].y1 <= v[j].y1 && v[j].y1 <= v[i].y2) && (v[j].x1 <= v[i].x1 && v[i].x1 <= v[j].x2)) {
			return 1;
		}
	}
	else {
		if ((v[i].x1 <= v[j].x1 && v[j].x1 <= v[i].x2) && (v[j].y1 <= v[i].y1 && v[i].y1 <= v[j].y2)) {
			return 1;
		}
	}
	return 0;
}
int bfs()
{
	queue<int> q;

	vector<int> dist(k, 0); //카운팅

	vector<bool> visit(k, 0); //방문 추적

	for (int i = 0; i < k; i++)
	{
		//시작할 수 있는 점과 목적지를 찾는다. 
		if (v[i].x1 == v[i].x2)
		{
			if (v[i].x1 == sx && v[i].y1 <= sy && sy <= v[i].y2)
			{
				q.push(i);
				visit[i] = 1;
			}
			if (v[i].x1 == ex && v[i].y1 <= ey && ey <= v[i].y2)
				isEnd[i] = 1;
		}
		else
		{
			if (v[i].y1 == sy && v[i].x1 <= sx && sx <= v[i].x2)
			{
				q.push(i);
				visit[i] = 1;
			}
			if (v[i].y1 == ey && v[i].x1 <= ex && ex <= v[i].x2)
				isEnd[i] = 1;
		}
	}

	while (!q.empty() && !isEnd[q.front()]) //비어있고 마지막 정류장이 있는 스택이 true면 멈춤
	{
		int i = q.front();

		int d = dist[i];

		for (int j = 0; j<k; ++j)
		{
			if (adj(i, j) && !visit[j])     // adj가 트루고 방문한적이 없으면
			{
				q.push(j);
				visit[j] = 1;
				dist[j] = d + 1;            // 큐에 push 후 방문 처리 후 ++1 해준다.
			}
		}
		q.pop(); // 앞에있는 큐를 pop
	}

	return dist[q.front()] + 1; //처음 탄거 카운팅하기위해 +1
}

int main()
{
	cin >> n >> m;          // x, y
	cin >> k;             // 버스의 갯수
	isEnd = vector<bool>(k, 0);

	for (int i = 0; i<k; i++)
	{
		int b, x1, y1, x2, y2;

		cin >> b >> x1 >> y1 >> x2 >> y2;     // 운행 갯수;

		if (x1 == x2)
		{
			if (y1 > y2)
				swap(y1, y2);
		}
		else
		{
			if (x1 > x2)
				swap(x1, x2);
		}
		v.push_back(bus(b, x1, y1, x2, y2));
	}

	cin >> sx >> sy >> ex >> ey;  // sxy - 출발 // exy 목적지

	cout << bfs() << endl;

	return 0;
}