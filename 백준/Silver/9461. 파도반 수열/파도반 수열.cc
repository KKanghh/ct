#include <bits/stdc++.h>
using namespace std;
long long D[101];

int main() {
	
	D[1] = 1;
	D[2] = 1;
	D[3] = 1;
	D[4] = 2;
	D[5] = 2;

	for (int i = 6; i <= 100; i++) {
		D[i] = D[i - 1] + D[i - 5];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << D[n] << '\n';
	}
}