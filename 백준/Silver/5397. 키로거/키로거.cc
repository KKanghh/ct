#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		list<char> result;
		list<char>::iterator t = result.begin();
		string input;
		cin >> input;

		for (char e : input) {
			if (e == '<') {
				if (t != result.begin()) t--;
			}
			else if (e == '>') {
				if (t != result.end()) t++;
			}
			else if (e == '-') {
				if (t == result.begin()) continue;
				t--;
				t = result.erase(t);
			}
			else {
				result.insert(t, e);
			}
		}

		for (char e : result) cout << e;
		cout << '\n';
	}
}