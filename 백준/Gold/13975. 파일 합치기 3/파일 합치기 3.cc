#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		while (n--) {
			int k;
			cin >> k;
			pq.push(k);
		}
		long long cnt = 0;
		while (pq.size() > 1) {
			long long t = 0;
			t += pq.top();
			pq.pop();
			t += pq.top();
			pq.pop();
			cnt += t;
			pq.push(t);
		}
		cout << cnt << '\n';
	}
}