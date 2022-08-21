#include <bits/stdc++.h>
using namespace std;
int cnt[10], sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int tmp = s[i] - '0';
		cnt[tmp]++;
		sum += tmp;
	}

	if (cnt[0] == 0 || sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	for (int i = 9; i >= 0; i--) {
		int k = cnt[i];
		while (k--) cout << i;
	}
}