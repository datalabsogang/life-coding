#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int n, r, queen[20];

void f(int x, int y) {
	for (int i = 1; i < x; i++)
		if (y == queen[i] || abs(queen[i] - y) == abs(x - i))
			return;

	if (x == n) {
		if (r < 3) {
			for (int i = 1; i <= n; i++)
				printf("%d ", queen[i]);
			puts("");
		}
		r++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		queen[x + 1] = i;
		f(x + 1, i);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		queen[1] = i;
		f(1, i);
	}
	cout << r;
	return 0;
}

