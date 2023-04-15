#include <bits/stdc++.h>
using namespace std;
int A[15];
bool chosen[15];
int sum, l, r, x, cnt, n;
deque<int> V;

void dfs(int m, int k, int c) {
	if (m == k) {
		int sum = 0;
		for (int e : V) sum += e;
		if (sum >= l && sum <= r && *max_element(V.begin(), V.end()) - *min_element(V.begin(), V.end()) >= x) cnt++;
		return;
	}

	for (int i = c; i < n; i++) {
		V.push_back(A[i]);
		dfs(m, k + 1, i + 1);
		V.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) cin >> A[i];


	for (int i = 2; i <= n; i++) dfs(i, 0, 0);

	cout << cnt;

}