#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	regex re("^[A-F]?A+F+C+[A-F]?$");

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (regex_match(s, re)) cout << "Infected!\n";
		else cout << "Good\n";
	}
}