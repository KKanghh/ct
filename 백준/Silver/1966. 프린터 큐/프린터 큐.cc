#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--) {
		queue<pair<int, int>> Q;
		vector<int> V;
		int N, M, cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			V.push_back(temp);
			Q.push({ i, temp });
		}
		sort(V.begin(), V.end());
		while (true) {
			if (Q.front().Y == V[V.size() - 1]) {
				cnt++;
				if (Q.front().X == M) {
					cout << cnt << '\n';
					break;
				}
				Q.pop();
				V.pop_back();
			}
			else {
				Q.push(Q.front());
				Q.pop();
			}
		}

		while (!Q.empty()) Q.pop();
		while (!V.empty()) V.pop_back();
	}
}