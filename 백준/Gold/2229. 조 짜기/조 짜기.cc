#include <bits/stdc++.h>
using namespace std;
int D[1005][1005];
int score[1001], n;
int ans[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> score[i];

	for (int i = 1; i <= n; i++) {
		int mn = score[i];
		int mx = score[i];
		for (int j = i; j <= n; j++) {
			mn = min(mn, score[j]);
			mx = max(mx, score[j]);
			D[i][j] = mx - mn;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i] = max(ans[i], ans[j - 1] + D[j][i]);
		}
	}
	
	cout << ans[n];
}