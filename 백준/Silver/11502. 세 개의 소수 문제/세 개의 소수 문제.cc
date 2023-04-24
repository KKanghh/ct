#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime(1001, true);
int S[1001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	isprime[1] = false;

	for (int i = 2; i * i <= 1000; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= 1000; j += i) isprime[j] = false;
		}
	}

	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j * 2 <= i; j++) {
			if (isprime[j] && isprime[i - j]) {
				S[i][0] = j;
				S[i][1] = i - j;
				break;
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> V;
		for (int i = 2; i <= n; i++) {
			if (!isprime[i]) continue;
			if (S[n - i][0] == 0) continue;

			V.push_back(i);
			V.push_back(S[n - i][0]);
			V.push_back(S[n - i][1]);
			sort(V.begin(), V.end());
			break;
		}

		if (V.size() == 0) cout << 0 << '\n';
		else {
			cout << V[0] << ' ' << V[1] << ' ' << V[2] << '\n';
		}
	}
}