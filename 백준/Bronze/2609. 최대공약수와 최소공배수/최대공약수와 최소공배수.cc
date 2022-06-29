#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	cin >> a >> b;
	int i = min(a, b);
	for (; i > 1; i--) {
		if (a % i == 0 && b % i == 0) break;
	}

	cout << i << '\n' << a * b / i;
}