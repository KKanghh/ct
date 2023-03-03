#include <bits/stdc++.h>
using namespace std;
int D[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		fill(D, D + 10001, 0);
		D[0] = 1;
		vector<int> K;
		int n;
		int m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			K.push_back(k);
		}
		cin >> m;
		for (int i = 0; i < n; i++) {
			for (int j = K[i]; j <= m; j++) {
				D[j] += D[j - K[i]];
			}
		}

		cout << D[m] << '\n';
	}
}