#include <bits/stdc++.h>
using namespace std;
int D[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(D + 1, D + 11, -1);

	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		int cow, p;
		cin >> cow >> p;
		if (D[cow] == -1) {
			D[cow] = p;
			continue;
		}

		if (D[cow] != p) {
			cnt++;
			D[cow] = p;
		}
	}

	cout << cnt;
}