#include <bits/stdc++.h>
using namespace std;
int D[100000];
int mx = -1e7;
int sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> D[i];
	for (int i = 0; i < k; i++) sum += D[i];
	mx = max(sum, mx);

	for (int i = k; i < n; i++) {
		sum -= D[i - k];
		sum += D[i];
		mx = max(sum, mx);
	}

	cout << mx;
}