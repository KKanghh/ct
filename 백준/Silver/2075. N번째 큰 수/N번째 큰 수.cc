#include <bits/stdc++.h>
using namespace std;
int board[1500][1500];
priority_queue<tuple<int, int, int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		pq.push({ board[n - 1][i], n - 1, i });
	}
	
	for (int i = 0; i < n - 1; i++) {
		int num, x, y;
		tie(num, x, y) = pq.top();
		pq.pop();
		pq.push({ board[x - 1][y], x - 1, y });
	}
	int num, x, y;
	tie(num, x, y) = pq.top();
	cout << num;
}