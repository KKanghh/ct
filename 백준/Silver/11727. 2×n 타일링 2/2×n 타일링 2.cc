#include <bits/stdc++.h>
using namespace std;
int D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	D[1] = 1;
	D[2] = 3;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
	}

	cout << D[n];

}