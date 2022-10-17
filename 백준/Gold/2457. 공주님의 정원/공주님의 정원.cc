#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<pair<int, int>, pair<int, int>> flower[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> flower[i].X.X >> flower[i].X.Y >> flower[i].Y.X >> flower[i].Y.Y;
	sort(flower, flower + n);
	int sm = 3, sd = 1, tm = 3, td = 1, fm = 11, fd = 30;
	int i = 0, ans = 0;;
	while (tm <= fm) {
		int cnt = 0;
		for (; flower[i].X.X < sm || (flower[i].X.X == sm && flower[i].X.Y <= sd); i++) {
			cnt++;
			if (flower[i].Y.X > tm || (flower[i].Y.X == tm && flower[i].Y.Y > td)) {
				tm = flower[i].Y.X;
				td = flower[i].Y.Y;
			}
		}
		if (cnt == 0) {
			cout << 0;
			return 0;
		}
		ans++;
		sm = tm;
		sd = td;
	}

	cout << ans;
}