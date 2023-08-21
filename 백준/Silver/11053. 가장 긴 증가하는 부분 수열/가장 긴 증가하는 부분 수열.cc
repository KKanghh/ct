#include <bits/stdc++.h>
using namespace std;
int A[1000], D[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	fill(D, D + n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] > A[j]) D[i] = max(D[i], D[j] + 1);
		}
	}

	cout << *max_element(D, D + n);
}