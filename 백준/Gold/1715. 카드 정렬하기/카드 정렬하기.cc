#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int s;
		cin >> s;
		q.push(s);
	}

	int cnt = 0;
	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		cnt += a + b;
		q.push(a + b);
	}
	cout << cnt;
}