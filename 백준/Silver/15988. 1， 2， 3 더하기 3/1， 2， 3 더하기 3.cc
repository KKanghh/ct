#include <bits/stdc++.h>
using namespace std;
#define LMT 1000000009

long long D[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	for (int i = 4; i <= 1000000; i++) D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % LMT;

	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << D[n] << '\n';
	}

}