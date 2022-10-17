#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	deque<int> D;

	while (num--) {
		string input;
		cin >> input;

		if (input == "push_front") {
			int add;
			cin >> add;
			D.push_front(add);
		}
		else if (input == "push_back") {
			int add;
			cin >> add;
			D.push_back(add);
		}
		else if (input == "pop_front") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (input == "size") {
			cout << D.size() << '\n';
		}
		else if (input == "empty") {
			cout << D.empty() << '\n';
		}
		else if (input == "front") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
			}
		}
		else {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
			}
		}
	}
}