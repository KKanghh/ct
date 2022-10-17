#include <bits/stdc++.h>
using namespace std;

int D[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else {
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}

	cout << D[a.length()][b.length()];
}