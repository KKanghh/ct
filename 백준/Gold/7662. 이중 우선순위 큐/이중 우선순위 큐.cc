#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		map<int, int> Q;

		while (k--) {
			char o;
			int n;
			cin >> o >> n;
			if (o == 'I') {
				if (Q.count(n)) Q[n]++;
				else Q[n] = 1;
			}
			else if (o == 'D' && Q.size() > 0) {
				map<int, int>::iterator e;
				if (n == 1) e = prev(Q.end());
				else e = Q.begin();
				if(!--(e->second)) Q.erase(e);
			}
		}

		if (Q.size() == 0) cout << "EMPTY\n";
		else cout << prev(Q.end())->first << ' ' << Q.begin()->first << '\n';
	}
}