#include <bits/stdc++.h>
using namespace std;
int w[6], d[6], l[6];
bool possible;

void dfs(int a, int b) {
	if (a == 5) {
		possible = possible || (!w[0] && !w[1] && !w[2] && !w[3] && !w[4] && !w[5] && !d[0] && !d[1] && !d[2] && !d[3] && !d[4] && !d[5] && !l[0] && !l[1] && !l[2] && !l[3] && !l[4] && !l[5]);
		return;
	}
	if (d[a] > 0 && d[b] > 0) {
		d[a]--;
		d[b]--;
		if (b == 5) dfs(a + 1, a + 2);
		else dfs(a, b + 1);
		d[a]++;
		d[b]++;
	}
	if (w[a] > 0 && l[b] > 0) {
		w[a]--;
		l[b]--;
		if (b == 5) dfs(a + 1, a + 2);
		else dfs(a, b + 1);
		w[a]++;
		l[b]++;
	}
	if (l[a] > 0 && w[b] > 0) {
		l[a]--;
		w[b]--;
		if (b == 5) dfs(a + 1, a + 2);
		else dfs(a, b + 1);
		l[a]++;
		w[b]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		possible = false;
		for (int j = 0; j < 6; j++) {
			cin >> w[j] >> d[j] >> l[j];
		}

		dfs(0, 1);

		cout << possible << ' ';
	}
}