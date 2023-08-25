#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	string t = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			reverse(t.begin(), t.end());
			cout << t;
			t.clear();
			while (s[i] != '>') t.push_back(s[i++]);
			t.push_back(s[i]);
			cout << t;
			t.clear();
			continue;
		}
		if (s[i] == ' ') {
			reverse(t.begin(), t.end());
			t.push_back(s[i]);
			cout << t;
			t.clear();
			continue;
		}
		t.push_back(s[i]);
	}
	reverse(t.begin(), t.end());
	cout << t;

}