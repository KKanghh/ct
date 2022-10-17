#include <bits/stdc++.h>
using namespace std;
int fake[1000000], rel[1000000];
vector<int> D;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		fake[i] = k;
		rel[i] = k;
	}

	sort(fake, fake + n);

	D.push_back(fake[0]);
	for (int i = 1; i < n; i++) {
		if (fake[i] != fake[i - 1]) D.push_back(fake[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << lower_bound(D.begin(), D.end(), rel[i]) - D.begin() << ' ';
	}
}