#include <bits/stdc++.h>
using namespace std;
tuple<int, int, int> I[30];
int a, b, c;
int mn = 0x3f3f3f3f;
int sa, sb, sc, n, m;

void dfs(int cnt, int k) {
	if (cnt == 0) {
		mn = min(mn, abs(a - sa / m) + abs(b - sb / m) + abs(c - sc / m));
		return;
	}
	for (int i = k; i < n; i++) {
		int ta, tb, tc;
		tie(ta, tb, tc) = I[i];
		sa += ta; sb += tb; sc += tc;
		dfs(cnt - 1, i + 1);
		sa -= ta; sb -= tb; sc -= tc;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		I[i] = { x, y, z };
	}

	cin >> a >> b >> c;

	for (m = 2; m <= n && m <= 7; m++) {
		dfs(m, 0);
	}

	cout << mn;


}