#include <bits/stdc++.h>
using namespace std;
map<int, string> num;
map<string, int> name;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string k;
		cin >> k;
		num[i] = k;
		name[k] = i;
	}

	while (m--) {
		string q;
		cin >> q;
		if (q[0] >= '0' && q[0] <= '9') {
			int p = 0;
			for (int i = 0; i < q.length(); i++) {
				p = p * 10 + q[i] - '0';
			}
			cout << num[p] << '\n';
		}
		else {
			cout << name[q] << '\n';
		}
	}
}