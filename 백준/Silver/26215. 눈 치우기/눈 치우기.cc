#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		pq.push(k);
	}

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		cnt += b;

		pq.push(a - b);
	}

	cnt += pq.top();

	if (cnt > 1440) cout << -1;
	else cout << cnt;

}