#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> D[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.Y == b.Y) {
		return a.X < b.X;
	}
	return a.Y < b.Y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> D[i].X >> D[i].Y;
	}

	sort(D, D + n, cmp);
	int cnt = 0, en = 0;;

	for (int i = 0; i < n; i++) {
		if (D[i].X >= en) {
			cnt++;
			en = D[i].Y;
		}
	}

	cout << cnt;
}