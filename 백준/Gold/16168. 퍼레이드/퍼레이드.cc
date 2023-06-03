#include <bits/stdc++.h>
using namespace std;
int pre[3001];
int deg[3001];

int find(int n) {
	if (pre[n] < 0) return n;
	return pre[n] = find(pre[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (pre[a] == pre[b]) {
		pre[a]--;
	}

	if (pre[a] < pre[b]) pre[b] = a;
	else pre[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	fill(pre + 1, pre + v + 1, -1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		deg[a]++;
		deg[b]++;

		merge(a, b);
	}

	int k = find(1);
	int odd = 0, even = 0;
	for (int i = 1; i <= v; i++) {
		if (find(i) != k) {
			cout << "NO";
			return 0;
		}

		
		if (deg[i] % 2) odd++;
		else even++;
	}

	if (odd == 0 || odd == 2) cout << "YES";
	else cout << "NO";
}