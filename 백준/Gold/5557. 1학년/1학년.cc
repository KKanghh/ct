#include <bits/stdc++.h>
using namespace std;
int n;
int num[100];
long long D[100][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	D[0][num[0]]++;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (D[i - 1][j] == 0) continue;

			if (j - num[i] >= 0) D[i][j - num[i]] += D[i - 1][j];
			if (j + num[i] <= 20) D[i][j + num[i]] += D[i - 1][j];
		}
	}

	cout << D[n - 2][num[n - 1]];
}