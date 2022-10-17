#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	stack<char> S;
	stack<pair<int, unsigned int>> N;

	cin >> input;
	bool isValid = true;

	for (char e : input) {
		if (e == '(' || e == '[') {
			S.push(e);
		}
		else if (e == ')') {
			if (S.empty() || S.top() != '(') {
				isValid = false;
				break;
			}
			S.pop();
			int temp = 2;
			if (N.empty() || N.top().Y < S.size()) {
				N.push({ temp, S.size() });
			}
			else if (N.top().Y > S.size()) {
				temp *= N.top().X;
				N.pop();
				if (!N.empty() && N.top().Y == S.size()) {
					temp += N.top().X;
					N.pop();
				}
				N.push({ temp, S.size() });
			}
			else {
				temp += N.top().X;
				N.pop();
				N.push({ temp, S.size() });
			}
		}
		else if (e == ']') {
			if (S.empty() || S.top() != '[') {
				isValid = false;
				break;
			}
			S.pop();
			int temp = 3;
			if (N.empty() || N.top().Y < S.size()) {
				N.push({ temp, S.size() });
			}
			else if (N.top().Y > S.size()) {
				temp *= N.top().X;
				N.pop();
				if (!N.empty() && N.top().Y == S.size()) {
					temp += N.top().X;
					N.pop();
				}
				N.push({ temp, S.size() });
			}
			else {
				temp += N.top().X;
				N.pop();
				N.push({ temp, S.size() });
			}
		}
	}

	if (!S.empty()) isValid = false;
	if (isValid) cout << N.top().X;
	else cout << 0;
}