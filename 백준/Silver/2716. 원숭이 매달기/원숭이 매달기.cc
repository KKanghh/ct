#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string trash;
	getline(cin, trash);
	while (n--) {
		string s;
		int mx = 0, cnt = 0;
		getline(cin, s);
		for (char e: s) {
			if (e == '[') {
				cnt++;
			}
			else {
				mx = max(mx, cnt);
				cnt--;
			}
		}
		int ans = 1;
		for (int i = 0; i < mx; i++) ans *= 2;

		cout << ans << '\n';
	}
}