#include <bits/stdc++.h>
using namespace std;
int D[31][1001];
int a[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, w;
	cin >> t >> w;
	int jd = 1;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
		D[0][i] = a[i] == jd ? D[0][i - 1] + 1 : D[0][i - 1];
	}

	for (int i = 1; i <= w; i++) {
		jd = 3 - jd;
		for (int j = 1; j <= t; j++) {
			D[i][j] = max(D[i - 1][j - 1], D[i][j - 1]) + (a[j] == jd);
		}
	}

	int mx = 0;
	for (int i = 0; i <= w; i++) {
		mx = max(D[i][t], mx);
	}
	
	cout << mx;
}