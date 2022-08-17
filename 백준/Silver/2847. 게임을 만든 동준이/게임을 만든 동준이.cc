#include <bits/stdc++.h>
using namespace std;
int D[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> D[i];
	}
	int cnt = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (D[i] >= D[i + 1]) {
			cnt += D[i] - (D[i + 1] - 1);
			D[i] = D[i + 1] - 1;
		}
	}

	cout << cnt;
}