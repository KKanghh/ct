#include <bits/stdc++.h>
using namespace std;
string s[100000];
set<char> answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> s[i];

	for (char x = 'A'; x <= 'Z'; x++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][0] == x) cnt++;
		}

		if (cnt > 1) {
			for (int i = 0; i < n; i++) {
				answer.insert(max(s[i][1], x));
			}
		}

		if (cnt == 1) {
			for (int i = 0; i < n; i++) {
				if (s[i][0] == x) continue;
				answer.insert(max(s[i][1], x));
			}
		}
	}

	cout << answer.size() << '\n';
	for (char e : answer) cout << e << ' ';

}