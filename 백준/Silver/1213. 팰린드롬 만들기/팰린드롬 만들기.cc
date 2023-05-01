#include <bits/stdc++.h>
using namespace std;
int name[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, ans;
	cin >> s;

	for (char e : s) {
		name[e - 'A']++;
	}

	int len = s.size();
	int odd = -1;

	for (int i = 0; i < 26; i++) {
		while (name[i] >= 2) {
			ans.push_back('A' + i);
			name[i] -= 2;
		}
		if (name[i] == 1) {
			if (odd != -1) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}

			odd = i;
		}
	}

	cout << ans;
	if (odd != -1) cout << (char) ('A' + odd);
	reverse(ans.begin(), ans.end());
	cout << ans;

}