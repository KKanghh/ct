#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	cin >> s;
	int len = s.length();
	int i = 0;
	while (i < len) {
		cnt[s[i] - '0']++;
		int k = i;
		while (k < len && s[k] == s[i]) k++;
		i = k;
	}
	cout << min(cnt[0], cnt[1]);
}