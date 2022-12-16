#include <bits/stdc++.h>
using namespace std;
long long V[300001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (V[i] >= V[i + 1]) continue;

		if (V[i + 1] % V[i] == 0) V[i] = V[i + 1];
		else {
			V[i] *= (V[i + 1] / V[i] + 1);
		}
	}

	cout << V[0];


}