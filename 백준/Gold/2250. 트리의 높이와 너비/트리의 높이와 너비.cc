#include <bits/stdc++.h>
using namespace std;
int lc[10001], rc[10001], level[10001], parent[10001], col[10001];

int cnt = 1;

void inorder(int n) {
	if (lc[n] != 0) {
		level[lc[n]] = level[n] + 1;
		inorder(lc[n]);
	}
	col[n] = cnt++;
	if (rc[n] != 0) {
		level[rc[n]] = level[n] + 1;
		inorder(rc[n]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b != -1) {
			lc[a] = b;
			parent[b] = a;
		}
		if (c != -1) {
			rc[a] = c;
			parent[c] = a;
		}
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == 0) {
			root = i;
			break;
		}
	}
	level[root] = 1;
	inorder(root);

	int mxlev = 1;
	int mxwid = 1;

	for (int lev = 1; lev <= *max_element(level + 1, level + n + 1); lev++) {
		int mn = n, mx = 1;
		for (int i = 1; i <= n; i++) {
			if (level[i] != lev) continue;
			if (col[i] < mn) mn = col[i];
			if (col[i] > mx) mx = col[i];
		}
		if (mx - mn + 1 > mxwid) {
			mxlev = lev;
			mxwid = mx - mn + 1;
		}

	}

	cout << mxlev << ' ' << mxwid;
}