#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p' && i + 1 < s.size() && s[i + 1] == 'i') i++;
		else if (s[i] == 'k' && i + 1 < s.size() && s[i + 1] == 'a') i++;
		else if (s[i] == 'c' && i + 2 < s.size() && s[i + 1] == 'h' && s[i + 2] == 'u') i += 2;
		else {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}