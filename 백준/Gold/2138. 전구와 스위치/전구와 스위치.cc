#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int len, mn = 0x3f3f3f3f;
	string target, now;
	cin >> len >> now >> target;
	
	for (int i = 0; i < 2; i++) {
		string t = now;
		int cnt = 0;
		if (i == 1) {
			t[0] = '0' + '1' - t[0];
			t[1] = '0' + '1' - t[1];
			cnt++;
		}

		for (int j = 1; j < len; j++) {
			if (t[j - 1] != target[j - 1]) {
				t[j - 1] = '0' + '1' - t[j - 1];
				t[j] = '0' + '1' - t[j];
				if (j + 1 < len) t[j + 1] = '0' + '1' - t[j + 1];
				cnt++;
			}
		}

		if (t[len - 1] == target[len - 1]) mn = min(mn, cnt);
	}

	if (mn == 0x3f3f3f3f) cout << -1;
	else cout << mn;
}