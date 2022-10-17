#include <bits/stdc++.h>
using namespace std;
vector<bool> state(1000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	state[1] = false;
	for (int i = 2; i * i <= 1000000; i++) {
		if (state[i]) {
			for (int j = i * i; j <= 1000000; j+= i) {
				state[j] = false;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		int k = n / 2;
		while (k > 0) {
			if (state[k] && state[n - k]) cnt++;
			k--;
		}
		cout << cnt <<'\n';
	}
}