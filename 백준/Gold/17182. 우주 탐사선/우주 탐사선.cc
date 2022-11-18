#include <bits/stdc++.h>
using namespace std;
int dist[10][10], nxt[10][10];
bool visited[10];
vector<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
			if (i != j) nxt[i][j] = j;
			else nxt[i][j] = -1;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != k) Q.push_back(i);
	}
	int mn = 0x7f7f7f7f;
	do {
		int t = k;
		int len = 0;
		for (int e : Q) {
			len += dist[t][e];
			t = e;
		}
		mn = min(len, mn);
	} while (next_permutation(Q.begin(), Q.end()));

	cout << mn;
}