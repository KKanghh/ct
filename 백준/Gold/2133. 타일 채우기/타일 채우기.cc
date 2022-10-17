#include <bits/stdc++.h>
using namespace std;
int D[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	D[0] = 1;

	for (int i = 2; i <= n; i += 2) {
		int cnt = 0;
		for (int j = 0; j < i - 2; j++) {
			cnt += D[j] * 2;
		}
		cnt += D[i - 2] * 3;
		D[i] = cnt;
	}

	cout << D[n];
}