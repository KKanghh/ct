#include <bits/stdc++.h>
using namespace std;
int A[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) cin >> A[i];

	int k = 0, cnt = 0;
	for (int st = 0; st < n; st++) {
		k += A[st];
		if (st >= l) k -= A[st - l];

		if (k >= 129 && k <= 138) cnt++;
	}

	cout << cnt;
}