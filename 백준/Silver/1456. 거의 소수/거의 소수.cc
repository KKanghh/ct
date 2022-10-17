#include <bits/stdc++.h>
using namespace std;
vector<bool> state(10000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	state[1] = false;
	for (int i = 2; i * i <= 10000000; i++) {
		if (state[i]) {
			for (int j = i * i; j <= 10000000; j += i) state[j] = false;
		}
	}

	unsigned long long a, b;
	cin >> a >> b;

	for (unsigned long long i = 2; i * i <= b; i++) {
		if (state[i]) {
			for (unsigned long long j = i * i; j <= b; j *= i) {
				if (j >= a) cnt++;
				if (j >= LLONG_MAX / i) break;
			}
		}
	}

	cout << cnt;
	
}