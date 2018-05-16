#include <stdio.h>

int N, K, S, E;
char A[1001][31];

#define YES 1
#define NO 0


typedef struct {
	int code_idx;
	int queue_idx;
} Node;

Node queue[1001];
int wp, rp;
void EnQueue(Node node) { queue[wp++] = node; }
Node DeQueue() { return queue[rp++]; }
int IsEmpty() { return (wp == rp) ? YES : NO; }

int H(char* code1, char* code2)
{
	int cnt = 0;
	for (int i = 0; i < K; i++)
	{
		if (code1[i] != code2[i])
			if (cnt++ > 1)
				return -1;
	}
	return cnt;
}

int V[1001];

int Do_BFS() {
	Node node = { S, -1 };
	EnQueue(node);
	V[S] = YES;

	while (IsEmpty() == NO)
	{
		node = DeQueue();
		for (int i = 1; i <= N; i++) {
			if (V[i] == NO &&
				H(A[node.code_idx], A[i]) == 1) {
				Node _node = { i, rp - 1 };
				if (i == E) {
					EnQueue(_node);
					return wp - 1;
				}
				V[i] = YES;
				EnQueue(_node);
			}
		}
	}
	return -1;
}

void Print_Path(int idx) {
	if (idx == -1)
		return;
	Print_Path(queue[idx].queue_idx);
	printf("%d ", queue[idx].code_idx);
}

int main() {

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf("%s", A[i]);

	scanf("%d %d", &S, &E);


	int ret = Do_BFS();
	if (ret == -1)
		printf("%d\n", ret);
	else
		Print_Path(ret);

	return 0;
}