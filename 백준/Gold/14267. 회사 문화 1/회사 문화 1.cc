#include <bits/stdc++.h>
using namespace std;
vector<int> child[100001];
int ching[100001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int parent;
		cin >> parent;
		if (i == 1) continue;

		child[parent].push_back(i);
	}

	while (m--) {
		int i, w;
		cin >> i >> w;
		ching[i] += w;
	}

	Q.push(1);
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int e : child[k]) {
			ching[e] += ching[k];
			Q.push(e);
		}
	}

	for (int i = 1; i <= n; i++) cout << ching[i] << ' ';

}