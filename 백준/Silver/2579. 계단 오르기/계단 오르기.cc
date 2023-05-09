#include <bits/stdc++.h>
using namespace std;
int stair[301];
int D[301][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> stair[i];

	D[1][0] = stair[1];

	for (int i = 2; i <= n; i++) {
		D[i][0] = max(D[i - 2][0], D[i - 2][1]) + stair[i];
		D[i][1] = D[i - 1][0] + stair[i];
	}

	cout << max(D[n][0], D[n][1]);
}