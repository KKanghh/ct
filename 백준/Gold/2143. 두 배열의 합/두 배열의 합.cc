#include <bits/stdc++.h>
using namespace std;
int A[1000], B[1000], n, m, t, D[1001];
long long cnt;
vector<int> V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];

	for (int i = 0; i < n; i++) D[i + 1] = D[i] + A[i];
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			V.push_back(D[i] - D[j]);
		}
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < m; i++) D[i + 1] = D[i] + B[i];
	for (int i = m; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			int k = D[i] - D[j];
			cnt += upper_bound(V.begin(), V.end(), t - k) - lower_bound(V.begin(), V.end(), t - k);
		}
	}

	cout << cnt;
}