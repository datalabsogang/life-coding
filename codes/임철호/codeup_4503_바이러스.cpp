#include <stdio.h> 
#include <iostream>
#include <vector>
#include <deque>


using namespace std;

int n, e;

deque<int> dq;

bool visited[100 + 10]; // �湮 ���� 
int adjm[110][110]; // �������
int number = -1; // �ڽ��� �������� �ʾ� -1���� ����

int goes()
{

	while (!dq.empty())
	{
		//��� �湮
		int current = dq.front();

		dq.pop_front();

		number++;
		//�ڽ� ��� ���� �ֱ�
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
	cin >> n; // ����
	cin >> e; // ��� ����

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