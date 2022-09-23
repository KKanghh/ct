#include <bits/stdc++.h>
using namespace std;
int vote[101];
int like[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		fill(vote, vote + 101, 0);
		int c, v;
		cin >> c >> v;
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> like[i][j];
			}
		}

		for (int i = 1; i <= v; i++) {
			vote[like[i][1]]++;
		}

		int* mx = max_element(vote + 1, vote + c + 1);
		if (*mx > (v / 2)) {
			cout << mx - vote << ' ' << 1 << '\n';
			continue;
		}
		int one = 0, second = 0;
		for (int i = 1; i <= c; i++) {
			if (vote[i] > vote[one]) {
				second = one;
				one = i;
			}
			else if (vote[i] > vote[second]) second = i;
		}
		int onev = 0, twov = 0;
		for (int i = 1; i <= v; i++) {
			int j = 1;
			while (like[i][j] != one && like[i][j] != second) j++;
			if (like[i][j] == one) onev++;
			else twov++;
		}
		if (onev > twov) cout << one;
		else cout << second;

		cout << ' ' << 2 << '\n';
	}
}