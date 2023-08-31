#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	string c = a;
	string d = b;

	while (c.size() % d.size()) {
		c += a;
	}
	while (c.size() > d.size()) {
		d += b;
	}
	// cout << c << '\n' << d << '\n';
	cout << (c == d);
}