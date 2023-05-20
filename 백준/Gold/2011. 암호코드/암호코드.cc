#include <bits/stdc++.h>
using namespace std;
int D[5001], num[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	
	for (int i = 0; i < n; i++) {
		num[i + 1] = s[i] - '0';
	}

	D[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (num[i] > 0) D[i] = D[i - 1] % 1000000;
        int t = num[i - 1] * 10 + num[i];
		if (t >= 10 && t <= 26) D[i] = (D[i] + D[i - 2]) % 1000000;
	}

	cout << D[n];
}