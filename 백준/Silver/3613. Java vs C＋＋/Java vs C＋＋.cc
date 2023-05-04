#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	string ans = "";
	bool java = false;
	bool cpp = false;
	bool error = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 'z' && s[i] >= 'a') {
			ans.push_back(s[i]);
		}
		else if (s[i] == '_') {
			if (i + 1 < s.size() && s[i + 1] >= 'a' && s[i + 1] <= 'z' && i != 0) {
				ans.push_back((char)(s[i + 1] - 'a' + 'A'));
				i++;
				cpp = true;
			}
			else error = true;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (i == 0) error = true;
			ans.push_back('_');
			ans.push_back((char)(s[i] - 'A' + 'a'));
			java = true;
		}
	}

	if ((java && cpp) || error) cout << "Error!";
	else cout << ans;
	
}