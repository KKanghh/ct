#include <bits/stdc++.h>
using namespace std;
int lane[100001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	lane[N] = 1;
	Q.push(N);
	int cnt = 0;
	while (!Q.empty()) {
		int s = Q.front();
		cnt++;
		//cout << s << ' ' << lane[s] << '\n';
		Q.pop();
		int t = 2 * s;
		while (t < 100001 && lane[t] == 0 && t != 0) {
			lane[t] = lane[s];
			Q.push(t);
			//cout << s << " - push 2배 :" << t << '\n';
			t *= 2;
		}
		for (int e : {s - 1, s + 1}) {
			if (e < 0 || lane[e] > 0 || e > 100001) continue;
			lane[e] = lane[s] + 1;
			Q.push(e);
			//cout << s << " - push +1 -1 :" << e << '\n';
		}
	}
	cout << lane[K] - 1;
}