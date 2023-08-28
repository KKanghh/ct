#include <bits/stdc++.h>
using namespace std;
bool explode[1000000];
stack<char> S;
stack<char> T;
string s, p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> p;

	for (int i = s.size() - 1; i >= 0; i--) {
		S.push(s[i]);
		if (S.top() == p[0]) {
			for (int j = 0; j < p.size(); j++) {
				if (!S.empty() && S.top() == p[j]) {
					T.push(S.top());
					S.pop();
				}
				else break;
			}

			if (T.size() == p.size()) {
				while (!T.empty()) T.pop();
			}
			else {
				while (!T.empty()) {
					S.push(T.top());
					T.pop();
				}
			}

		}
	}

	if (S.empty()) cout << "FRULA";
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}