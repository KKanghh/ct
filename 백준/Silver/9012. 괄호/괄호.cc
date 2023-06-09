#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		stack<int> S;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') S.push(1);
			else {
				if (S.empty()) {
					S.push(1);
					break;
				}
				else S.pop();
			}
		}
		
		if (S.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}