#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	stack<char> S;
	int stick = 0;
	bool razor = true;
	cin >> input;
	for (char e : input) {
		if (e == '(') {
			S.push(e);
			razor = true;
		}
		else {
			if (razor) {
				S.pop();
				stick += S.size();
				razor = false;
			}
			else {
				S.pop();
				stick++;
			}
		}
	}

	cout << stick;
}