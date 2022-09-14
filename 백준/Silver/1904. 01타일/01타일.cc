#include <bits/stdc++.h>
using namespace std;
int D[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[1] = 1;
	D[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		D[i] = (D[i - 1] + D[i - 2]) % 15746;
	}

	cout << D[n];
}