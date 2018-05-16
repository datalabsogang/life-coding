#include <stdio.h> 
#include <iostream>
#include <vector>
#include <deque>


using namespace std;

int n, e;

deque<int> dq;

bool visited[100 + 10]; // 방문 검출 
int adjm[110][110]; // 인접행렬
int number = -1; // 자신은 포함하지 않아 -1부터 시작

int goes()
{

	while (!dq.empty())
	{
		//노드 방문
		int current = dq.front();

		dq.pop_front();

		number++;
		//자식 노드 덱에 넣기
		for (int i = 0; i <= n; i++)
		{
			if (adjm[current][i] != 0 && visited[i] == false)
			{
				visited[i] = true;
				dq.push_back(i);
			}
		}
	}
	return number;
}


int main()
{
	cin >> n; // 갯수
	cin >> e; // 노드 갯수

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		adjm[a][b] = 1;
		adjm[b][a] = 1;
	}

	dq.push_back(1);
	visited[1] = true;
	cout << goes() << endl;
	return 0;
}