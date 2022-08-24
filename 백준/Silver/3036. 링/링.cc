#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (a > 0 && b > 0) {
		int tmp = b;
		a %= b;
		b = a;
		a = tmp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a;
	cin >> a;
	n--;
	while (n--) {
		int k;
		cin >> k;
		int g = gcd(a, k);
		cout << a / g << '/' << k / g << '\n';
	}
}