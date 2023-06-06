#include <bits/stdc++.h>
using namespace std;
unordered_set<long long> S;
int board[9][9];
int n, m;
long long num;
long long mx = -1;

void check(int x, int y) {
	for (int i = -n; i < n; i++) {
		for (int j = -m; j < m; j++) {
			int tx = x;
			int ty = y;
			num = 0;
			while (tx < n && tx >= 0 && ty < m && ty >= 0) {
				num = num * 10 + board[tx][ty];
				if (S.count(num)) mx = max(num, mx);
				if (i == 0 && j == 0) break;
				tx += i; ty += j;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (long long i = 0; i * i < 1e10; i++) S.insert(i * i);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check(i, j);
		}
	}

	cout << mx;

}