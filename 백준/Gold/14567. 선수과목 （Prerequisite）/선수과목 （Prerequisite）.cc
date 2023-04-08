#include <bits/stdc++.h>
using namespace std;
int ind[1001], sem[1001];
vector<int> g[1001];
queue<int> Q;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		ind[b]++;
		g[a].push_back(b);
	}

	int tik = 0;

	while (true) {
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0 && sem[i] == 0) Q.push(i);
		}

		if (Q.empty()) break;

		tik++;

		while (!Q.empty()) {
			int a = Q.front();
			Q.pop();
			sem[a] = tik;
			for (int e : g[a]) ind[e]--;
		}
	}

	for (int i = 1; i <= n; i++) cout << sem[i] << ' ';
}