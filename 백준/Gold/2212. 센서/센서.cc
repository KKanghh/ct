#include <bits/stdc++.h>
using namespace std;
int num[10000];
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num, num + n);

	for (int i = 1; i < n; i++) pq.push(num[i] - num[i - 1]);

	for (int i = 1; i < k && !pq.empty(); i++) pq.pop();

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}