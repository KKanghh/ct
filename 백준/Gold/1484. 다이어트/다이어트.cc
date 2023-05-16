#include <bits/stdc++.h>
using namespace std;

set<long long> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int g;
	cin >> g;
	bool none = true;

	for (long long i = 1; i <= 50005; i++) S.insert(i * i);
	
	for (long long i = 1; i <= 50005; i++) {
		if (S.count(i * i - g)) {
			none = false;
			cout << i << '\n';
		}
	}

	if (none) cout << -1;
}