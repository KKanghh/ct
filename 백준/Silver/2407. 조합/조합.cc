#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> C[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	C[0][0] = { 0, 1 };

	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) C[i][j] = { 0, 1 };
			else {
				pair<long long, long long> a, b;
				a = C[i - 1][j - 1];
				b = C[i - 1][j];
				if (1e12 - a.second - b.second <= 0) {
					C[i][j] = { a.first + b.first + 1, a.second - 1e12 + b.second };
				}
				else C[i][j] = { a.first + b.first, a.second + b.second };
			}
		}
	}
	int cnt = 1;
	long long ten = 10;
	while (ten < C[n][m].second) {
		cnt++;
		ten *= 10;
	}
	if (C[n][m].first > 0) {
		cout << C[n][m].first;
		for (; cnt < 12; cnt++) cout << 0;
	}
	cout << C[n][m].second;
}