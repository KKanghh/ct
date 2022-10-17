#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int k = 1;
	while (n > k) {
		n -= k;
		k++;
	}
	k++;
	if (k % 2 == 1) cout << n << '/' << k - n;
	else cout << k - n << '/' << n;
}