#include <bits/stdc++.h>
using namespace std;
char beach[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> beach[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (beach[i][j] == '#') {
				if (j - 1 >= 0 && beach[i][j - 1] == '.') cnt++;
				if (j + 1 < m && beach[i][j + 1] == '.') cnt++;
				if (i - 1 >= 0 && j - 1 + i % 2 >= 0 && beach[i - 1][j - 1 + i % 2] == '.') cnt++;
				if (i - 1 >= 0 && j + i % 2 < m && beach[i - 1][j + i % 2] == '.') cnt++;
				if (i + 1 < n && j - 1 + i % 2 >= 0 && beach[i + 1][j - 1 + i % 2] == '.') cnt++;
				if (i + 1 < n && j + i % 2 < m && beach[i + 1][j + i % 2] == '.') cnt++;
			}
		}
	}

	cout << cnt;
}