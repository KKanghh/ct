#include <bits/stdc++.h>
using namespace std;
int d[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	int n;
	cin >> n;
	cout << d[n];
}