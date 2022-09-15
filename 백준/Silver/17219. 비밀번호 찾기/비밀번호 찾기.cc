#include <bits/stdc++.h>
using namespace std;
map<string, string> M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string URL, password;
	int n, m;
	cin >> n >> m;
	while (n--) {
		cin >> URL >> password;
		M[URL] = password;
	}
	while (m--) {
		cin >> URL;
		cout << M[URL] << '\n';
	}
}