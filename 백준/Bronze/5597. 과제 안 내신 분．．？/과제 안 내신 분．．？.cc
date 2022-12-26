#include <bits/stdc++.h>
using namespace std;
int c[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 28; i++) {
		int t;
		cin >> t;
		c[t]++;
	}

	for (int i = 1; i <= 30; i++) {
		if (c[i] == 0) cout << i << '\n';
	}
}