#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;

		cout << a << " & " << b << " are";

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a != b) cout << " NOT";
		cout << " anagrams.\n";

	}
}