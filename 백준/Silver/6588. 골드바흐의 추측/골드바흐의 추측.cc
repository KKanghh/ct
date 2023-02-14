#include <bits/stdc++.h>
using namespace std;
vector<bool> isprime(1000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	isprime[0] = false;
	isprime[1] = false;

	for (int i = 2; i * i < 1000001; i++) {
		if (!isprime[i]) continue;

		for (int j = i * i; j < 1000001; j += i) {
			isprime[j] = false;
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		bool find = false;
		for (int i = 2; i <= n / 2; i++) {
			if (isprime[i] && isprime[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				find = true;
				break;
			}
		}

		if (!find) cout << "Goldbach's conjecture is wrong.\n";
	}


}