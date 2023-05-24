#include <bits/stdc++.h>
using namespace std;
int D[201], M[1000];

int find(int n) {
	if (D[n] < 0) return n;
	else return D[n] = find(D[n]);
}

void merge(int n, int m) {
	n = find(n);
	m = find(m);

	if (n == m) return;

	if (D[n] == D[m]) D[n]--;
	if (D[n] < D[m]) D[m] = n;
	else D[n] = m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	fill(D, D + n + 1, -1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool l;
			cin >> l;
			if (l) merge(i, j);
		}
	}

	for (int i = 0; i < m; i++) cin >> M[i];

	bool ans = true;
	for (int i = 1; i < m; i++) {
		ans = ans && find(M[i - 1]) == find(M[i]);
	}

	if (ans) cout << "YES";
	else cout << "NO";
}