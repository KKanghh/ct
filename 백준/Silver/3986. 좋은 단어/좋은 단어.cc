#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, cnt = 0;
	cin >> num;
	string input;
	while (num--) {
		cin >> input;
		stack<char> S;

		for (char e : input) {
			if (!S.empty() && S.top() == e) S.pop();
			else S.push(e);
		}
		
		if (S.empty()) cnt++;
	}

	cout << cnt;
}