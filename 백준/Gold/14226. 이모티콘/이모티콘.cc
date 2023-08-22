#include <bits/stdc++.h>
using namespace std;
int D[1001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(D + 1, D + 1001, 0x3f3f3f3f);
	Q.push(1);
	D[1] = 0;

	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();

		int t = D[k] + 1;
		int s = k * 2;
		while (s <= 1000) {
			t++;
			if (t > D[s]) break;
			D[s] = t;
			Q.push(s);
			s += k;
		}

		t = D[k];
		s = k - 1;
		while (k >= 1) {
			t++;
			if (t > D[s]) break;
			D[s] = t;
			Q.push(s);
			s--;
		}
	}

	int s;
	cin >> s;
	cout << D[s];
}