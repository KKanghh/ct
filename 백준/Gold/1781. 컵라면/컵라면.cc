#include <bits/stdc++.h>
using namespace std;

vector<int> tik[200001];
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, r;
		cin >> t >> r;
		tik[t].push_back(r);
	}

	long long ramen = 0;

	for (int i = n; i > 0; i--) {
		for (int e : tik[i]) pq.push(e);
		if (pq.empty()) continue;
		ramen += pq.top();
		pq.pop();
	}

	cout << ramen;
}