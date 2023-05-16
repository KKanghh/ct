#include <bits/stdc++.h>
using namespace std;
pair<int, int> c[100000];
int mx = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t >> c[i].first >> c[i].second;
	}

	sort(c, c + n);

	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top() <= c[i].first) pq.pop();
		pq.push(c[i].second);
		int size = pq.size();
		mx = max(mx, size);
	}

	cout << mx;

}