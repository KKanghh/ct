#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;

	int num;
	cin >> num;

	while (num--) {
		string input;
		cin >> input;
		if (input == "push") {
			int add;
			cin >> add;
			Q.push(add);
		}
		else if (input == "front") {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		}
		else if (input == "back") {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
		else if (input == "size") {
			cout << Q.size() << '\n';
		}
		else if (input == "empty") {
			cout << Q.empty() << '\n';
		}
		else {
			if (Q.empty()) cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
	}
}