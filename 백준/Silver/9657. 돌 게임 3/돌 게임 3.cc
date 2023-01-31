#include <bits/stdc++.h>
using namespace std;
bool D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	D[1] = true;
	D[3] = true;
	D[4] = true;

	for (int i = 5; i <= n; i++) {
		D[i] = !D[i - 1] || !D[i - 3] || !D[i - 4];
	}

	if (D[n]) cout << "SK";
	else cout << "CY";
}