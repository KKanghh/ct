#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> S;
	int n;
	cin >> n;
	while (n--) {
		string name, go;
		cin >> name >> go;
		if (go == "leave") {
			S.erase(name);
		}
		else {
			S.insert(name);
		}
	}
	auto e = --S.end();
	while (e != S.begin()) cout << *e-- << '\n';
	//sort(S.begin(), S.end());
	cout << *e;
	//for (string s : S) cout << s << '\n';
}