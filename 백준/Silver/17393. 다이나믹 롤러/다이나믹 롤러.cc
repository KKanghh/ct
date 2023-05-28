#include <bits/stdc++.h>
using namespace std;
long long A[500000], B[500000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	for (int i = 0; i < n; i++) {
		int p = upper_bound(B, B + n, A[i]) - B;
		if (p <= i) cout << 0;
		else cout << p - i - 1;
		cout << ' ';
	}
}