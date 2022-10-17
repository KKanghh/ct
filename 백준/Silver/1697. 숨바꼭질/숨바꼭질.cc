#include <bits/stdc++.h>
using namespace std;

int line[100001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	line[N] = 1;
	Q.push(N);
	while (!Q.empty()) {
		int num = Q.front();
		if (num == K) {
			cout << line[num] - 1;
			return 0;
		}
		if (num + 1 < 100001 && !line[num + 1]) {
			line[num + 1] = line[num] + 1;
			Q.push(num + 1);
		}
		if (num - 1 >= 0 && !line[num - 1]) {
			line[num - 1] = line[num] + 1;
			Q.push(num - 1);
		}
		if (2 * num < 100001 && !line[2 * num]) {
			line[2 * num] = line[num] + 1;
			Q.push(2 * num);
		}
		Q.pop();
	}
}