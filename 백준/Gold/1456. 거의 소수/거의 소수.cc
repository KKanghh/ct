#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(1e7 + 1, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	prime[1] = false;
	for (int i = 2; i * i <= 1e7; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 1e7; j += i) prime[j] = false;
		}
	}

	long long a, b;
	cin >> a >> b;
	int cnt = 0;

	for (long long i = 1; i * i <= b; i++) {
		if (prime[i]) {
			long long t = i * i;
			while (true) {
				if (t >= a) cnt++;
				if (t > b / i) break;
				t *= i;
			}
		}
	}

	cout << cnt;
}