#include <bits/stdc++.h>
using namespace std;
int a[1001], D[1001], S[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				if (D[i] < D[j] + 1) {
					D[i] = D[j] + 1;
					S[i] = j;
				}
			}
		}
	}
	cout << *max_element(D + 1, D + n + 1) + 1 << '\n';
	int k = max_element(D + 1, D + n + 1) - D;
	stack<int> G;
	while (k > 0) {
		G.push(a[k]);
		k = S[k];
	}
	while (!G.empty()) {
		cout << G.top() << ' ';
		G.pop();
	}

}