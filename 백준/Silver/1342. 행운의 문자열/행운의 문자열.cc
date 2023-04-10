#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	int len = s.size();
	do {
		int cur = 1;
		bool check = true;

		while (cur < len) {
			if (s[cur - 1] == s[cur]) {
				check = false;
				break;
			}
			cur++;
		}

		if (check) cnt++;
	} while (next_permutation(s.begin(), s.end()));

	cout << cnt;
}