#include <bits/stdc++.h>
using namespace std;
vector<int> f[501];
int fr[501];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		f[a].push_back(b);
		f[b].push_back(a);
	}

	fr[1] = 1;
	Q.push(1);
	int cnt = 0;

	while (!Q.empty()) {
		int k;
		k = Q.front();
		Q.pop();
		//if (k == 2) continue;
		for (int e : f[k]) {
			if (fr[e] > 0) continue;
			cnt++;
			fr[e] = fr[k] + 1;
			if (fr[e] == 2) Q.push(e);
		}
	}

	cout << cnt;
}