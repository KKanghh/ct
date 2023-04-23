#include <bits/stdc++.h>
using namespace std;
int D[100001];
int coin[4] = { 1, 2, 5, 7 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	fill(D + 1, D + n + 1, 0x3f3f3f3f);

	for (int i = 1; i <= n; i++) {
		for (int e : coin) {
			if (e > i) continue;

			D[i] = min(D[i - e] + 1, D[i]);
		}
	}

	cout << D[n];
	
}