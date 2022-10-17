#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	string input;
	while (num--) {
		stack<char> S;
		bool isVPS = true;
		cin >> input;
		for (char e : input) {
			if (e == '(') {
				S.push(e);
			}
			else {
				if (S.empty()) {
					isVPS = false;
					break;
				}
				S.pop();
			}
		}

		if (!S.empty()) isVPS = false;
		if (isVPS) cout << "YES\n";
		else cout << "NO\n";
	}
}