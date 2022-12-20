#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;

	for (int i = 0; i < n; i++) a.push_back('@');
	for (int i = 0; i < 3 * n; i++) a.push_back(' ');
	for (int i = 0; i < n; i++) a.push_back('@');

	for (int i = 0; i < 5 * n; i++) {
		b.push_back('@');
	}

	for (int i = 0; i < n; i++) cout << a << '\n';
	for (int i = 0; i < n; i++) cout << b << '\n';
	for (int i = 0; i < n; i++) cout << a << '\n';
	for (int i = 0; i < n; i++) cout << b << '\n';
	for (int i = 0; i < n; i++) cout << a << '\n';
}