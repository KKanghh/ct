#include <bits/stdc++.h>
using namespace std;
pair<int, int> D[200000];
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> D[i].first >> D[i].second;
	}
	sort(D, D + n);
	int mx = 1;
	Q.push(D[0].second);
	for (int i = 1; i < n; i++) {
		if (D[i].first < Q.top()) {
			Q.push(D[i].second);
		}
		else {
			while (!Q.empty() && Q.top() <= D[i].first) Q.pop();
			Q.push(D[i].second);
		}
		int k = Q.size();
		mx = max(mx, k);
	}

	cout << mx;
}