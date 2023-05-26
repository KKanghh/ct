#include <bits/stdc++.h>
using namespace std;
string s[1000];
int target[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n, un;
	string t, m;
	cin >> k >> n;

	for (int i = 0; i < k; i++) t.push_back(' ');
	cin >> m;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		if (line[0] == '?') {
			un = i;
			continue;
		}
		s[i] = line;
	}

	for (int i = 0; i < k; i++) {
		int p = i;
		for (int j = 0; j < un; j++) {
			if (p > 0 && s[j][p - 1] == '-') p--;
			else if (p < k && s[j][p] == '-') p++;
		}
		t[p] = 'A' + i;
	}

	for (int i = 0; i < k; i++) {
		int p = i;
		for (int j = un + 1; j < n; j++) {
			if (p > 0 && s[j][p - 1] == '-') p--;
			else if (p < k && s[j][p] == '-') p++;
		}
		target[i] = p;
	}

	for (int i = 0; i < k - 1; i++) {
		if (t[i] == m[target[i]]) s[un].push_back('*');
		else if (t[i + 1] == m[target[i]]) {
			s[un].push_back('-');
			swap(t[i], t[i + 1]);
		}
		else break;
	}

	if (s[un].size() < k - 1) {
		for (int i = 0; i < k - 1; i++) cout << 'x';
		return 0;
	}

	for (int i = 0; i < k - 2; i++) {
		if (s[un][i] == '-' && s[un][i + 1] == '-') {
			for (int i = 0; i < k - 1; i++) cout << 'x';
			return 0;
		}
	}

	cout << s[un];
}