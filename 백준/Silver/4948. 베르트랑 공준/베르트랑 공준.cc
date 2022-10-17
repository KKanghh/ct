#include <bits/stdc++.h>
using namespace std;

vector<bool> D(246913, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[1] = false;
	for (int i = 2; i * i < 246913; i++) {
		if (D[i]) {
			for (int j = i * i; j < 246913; j += i) D[j] = false;
		}
	}

	while (true) {
		int n, cnt = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (D[i]) cnt++;
		}
		cout << cnt << '\n';
	}
}