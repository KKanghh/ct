#include <bits/stdc++.h>
using namespace std;
int D[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	fill(D, D + n + 1, 1000);
	D[0] = 0;
	D[1] = 1;
	int m = 2;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			D[i] = min(D[i], D[i - j * j]);
		}
		D[i]++;
	}
	cout << D[n];
}