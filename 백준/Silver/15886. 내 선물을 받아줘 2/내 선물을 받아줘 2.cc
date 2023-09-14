#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt = 1;

	for (int i = 0; i < n - 1; i++) {
		if (s.substr(i, 2) == "WE") cnt++;
	}
	cout << cnt;
}