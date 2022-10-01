#include <bits/stdc++.h>
using namespace std;
priority_queue<int> mn;
priority_queue<int, vector<int>, greater<int>> mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (i % 2 == 1) {
			mx.push(k);
			int t = mx.top();
			mx.pop();
			mn.push(t);
		}
		else {
			int t = mn.top();
			mn.pop();
			mn.push(min(t, k));
			mx.push(max(t, k));
		}
		cout << mn.top() << '\n';
	}
}