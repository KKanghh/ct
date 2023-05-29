#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int mx;
pair<int, int> c[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;

	sort(c, c + n);

	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top() <= c[i].first) pq.pop();
		pq.push(c[i].second);
		int s = pq.size();
		mx = max(s, mx);
	}

	cout << mx;
}