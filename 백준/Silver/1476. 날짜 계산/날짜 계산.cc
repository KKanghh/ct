#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int e = 15, s = 28, m = 19;
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = a; i <= e * s; i += e) {
		if ((i - b) % s == 0) {
			a = i;
			break;
		}
	}

	for (int i = a; i <= e * s * m; i += e * s) {
		if ((i - c) % m == 0) {
			cout << i;
			break;
		}
	}
}