#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, p;
	cin >> l >> p;

	for (int i = 0; i < 5; i++) {
		int k;
		cin >> k;
		cout << k - l * p << ' ';
	}
}