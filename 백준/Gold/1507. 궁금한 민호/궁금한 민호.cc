#include <bits/stdc++.h>
using namespace std;

int dist[20][20];
bool unit[20][20];
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	int cnt = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || j == k || i == k) continue;
				if (dist[i][j] == INF) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					cout << -1;
					return 0;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					dist[i][j] = INF;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != INF) cnt += dist[i][j];
		}
	}

	cout << cnt / 2;
}