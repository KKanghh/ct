#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	string input;
	getline(cin, input);
	while (input != ".") {
		stack<char> S;
		bool balance = true;
		for (char e : input) {
			if (e == '(' || e == '[') S.push(e);
			else if (e == ')') {
				if (S.empty() || S.top() != '(') {
					cout << "no" << '\n';
					balance = false;
					break;
				}
				else {
					S.pop();
				}
			}
			else if (e == ']') {
				if (S.empty() || S.top() != '[') {
					cout << "no" << '\n';
					balance = false;
					break;
				}
				else {
					S.pop();
				}
			}
		}
		if (balance) {
			if (S.empty()) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
		getline(cin, input);
	}
}