#include <bits/stdc++.h>
using namespace std;
int num[13], selected[13];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		int n;
		fill(selected, selected + 13, 1);
		fill(selected, selected + 6, 0);
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> num[i];
		do {
			for (int i = 0; i < n; i++) {
				if (selected[i] == 0) cout << num[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(selected, selected + n));
		cout << '\n';
	}

}