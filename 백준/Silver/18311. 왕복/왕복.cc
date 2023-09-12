#include <bits/stdc++.h>
using namespace std;
int dist[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> dist[i];

	for (int i = 0; i < n; i++) {
		if (k < dist[i]) {
			cout << i + 1;
			return 0;
		}
		k -= dist[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k < dist[i]) {
			cout << i + 1;
			return 0;
		}
		k -= dist[i];
	}

}