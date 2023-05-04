#include <bits/stdc++.h>
using namespace std;
int D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	D[0] = 1;
	D[1] = 1;
	
	for (int i = 2; i <= n; i++) D[i] = (D[i - 1] + D[i - 2] * 2) % 10007;

	cout << D[n];
}