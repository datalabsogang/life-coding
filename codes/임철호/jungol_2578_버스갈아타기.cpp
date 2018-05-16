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
	if (i == j)  //������ �񱳿� �ǹ̰� ���⿡ ����
		return 0;

	bool iv = v[i].x1 == v[i].x2 ? 1 : 0;
	bool jv = v[j].x1 == v[j].x2 ? 1 : 0;

	if (iv == 1 && jv == 1) //x���� ���� �� ���� ã�´�.
	{
		if (v[i].x1 != v[j].x1)  // i�� x1�� j�� x1�� �ٸ��� false.
			return 0;
		if ((v[i].y1 <= v[j].y1 && v[j].y2 <= v[i].y2) ||
			(v[j].y1 <= v[i].y1 && v[i].y2 <= v[j].y2) ||
			(v[j].y1 <= v[i].y2 && v[i].y1 <= v[j].y1 && v[i].y2 <= v[j].y2) ||
			(v[i].y1 <= v[j].y2 && v[j].y1 <= v[i].y1 && v[j].y2 <= v[i].y2))
		{
			return 1; //y���� �̾����� true
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

	vector<int> dist(k, 0); //ī����

	vector<bool> visit(k, 0); //�湮 ����

	for (int i = 0; i < k; i++)
	{
		//������ �� �ִ� ���� �������� ã�´�. 
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

	while (!q.empty() && !isEnd[q.front()]) //����ְ� ������ �������� �ִ� ������ true�� ����
	{
		int i = q.front();

		int d = dist[i];

		for (int j = 0; j<k; ++j)
		{
			if (adj(i, j) && !visit[j])     // adj�� Ʈ��� �湮������ ������
			{
				q.push(j);
				visit[j] = 1;
				dist[j] = d + 1;            // ť�� push �� �湮 ó�� �� ++1 ���ش�.
			}
		}
		q.pop(); // �տ��ִ� ť�� pop
	}

	return dist[q.front()] + 1; //ó�� ź�� ī�����ϱ����� +1
}

int main()
{
	cin >> n >> m;          // x, y
	cin >> k;             // ������ ����
	isEnd = vector<bool>(k, 0);

	for (int i = 0; i<k; i++)
	{
		int b, x1, y1, x2, y2;

		cin >> b >> x1 >> y1 >> x2 >> y2;     // ���� ����;

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

	cin >> sx >> sy >> ex >> ey;  // sxy - ��� // exy ������

	cout << bfs() << endl;

	return 0;
}