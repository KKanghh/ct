#include <bits/stdc++.h>
using namespace std;
bool open[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		fill(open + 1, open + n + 1, false);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) open[j] = !open[j];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += open[i];
		cout << cnt << '\n';
	}
}