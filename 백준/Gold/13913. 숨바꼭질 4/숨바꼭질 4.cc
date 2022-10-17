#include <bits/stdc++.h>
using namespace std;
int lane[100001], before[100001];
queue<int> Q;
stack<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	lane[N] = 1;
	Q.push(N);

	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (auto e : { t - 1, t + 1, 2 * t }) {
			if (e < 0 || e > 100000) continue;
			if (lane[e] > 0) continue;
			before[e] = t;
			lane[e] = lane[t] + 1;
			Q.push(e);
		}
	}

	cout << lane[K] - 1 << '\n';
	S.push(K);
	for (int i = K; i != N; i = before[i]) {
		S.push(before[i]);
	}
	while (!S.empty()) {
		cout << S.top() << ' ';
		S.pop();
	}
}