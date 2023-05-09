#include <bits/stdc++.h>
using namespace std;

long long D[2][91];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[1][1] = 1;
	
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		D[0][i] = D[0][i - 1] + D[1][i - 1];
		D[1][i] = D[0][i - 1];
	}

	cout << D[0][n] + D[1][n];
}