#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string s;
		getline(cin, s);
		
		if (s == "END") break;

		for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
		cout << '\n';
	}
}