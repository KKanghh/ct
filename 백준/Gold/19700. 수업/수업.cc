#include <bits/stdc++.h>
using namespace std;
int V[500000];
priority_queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int h, k;
		cin >> h >> k;
		Q.push({ h, k });
	}

	while (!Q.empty()) {
		int cur = lower_bound(V, V + 500000, Q.top().second) - V;
		V[cur - 1]++;
		Q.pop();

	}

	int ans = 499999;
	while (V[ans] > 0) {
		ans--;
	}
	cout << 499999 - ans;
}