#include <bits/stdc++.h>
using namespace std;
char board[9];
int d[8][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6}
};

int bfs() {
	queue<pair<string, int>> Q;
	set<string> S;

	Q.push({ board, 0 });
	S.insert(board);

	while (!Q.empty()) {
		string a;
		int b;
		tie(a, b) = Q.front();
		Q.pop();

		int cur = 1;
		for (; cur < 9; cur++) {
			if (a[cur] != a[cur - 1]) break;
		}

		if (cur == 9) return b;

		for (int i = 0; i < 8; i++) {
			string k = a;
			k[d[i][0]] = k[d[i][0]] == 'H' ? 'T' : 'H';
			k[d[i][1]] = k[d[i][1]] == 'H' ? 'T' : 'H';
			k[d[i][2]] = k[d[i][2]] == 'H' ? 'T' : 'H';

			if (S.count(k)) continue;

			S.insert(k);
			Q.push({ k, b + 1 });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> board[i * 3 + j];
			}
		}

		cout << bfs() << '\n';
	}
}