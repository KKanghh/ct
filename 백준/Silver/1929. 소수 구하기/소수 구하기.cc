#include <bits/stdc++.h>
using namespace std;
vector<bool> state(1000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	state[1] = false;

	int m, n;
	cin >> m >> n;

	for (int i = 2; i <= n; i++) {
		if (state[i]) {
			for (int j = i + i; j <= n; j += i) {
				state[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (state[i]) cout << i << '\n';
	}
}