#include <bits/stdc++.h>
using namespace std;

void change(char a) {
	char b;
	if (a >= 'a' && a <= 'z') {
		b = a - 32;
	}
	else b = a + 32;
	cout << b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (char e : s) {
		change(e);
	}
}