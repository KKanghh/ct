#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(100001, true);
int D[255];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	prime[0] = false;
	for (int i = 2; i * i <= 100000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 100000; j += i) prime[j] = false;
		}
	}

	string s;
	while (true) {
		cin >> s;
		if (s == "0") break;
		int mx = 0;
		for (int i = 0; i < s.length(); i++) {
			int x = 0;
			for (int j = i; j < i + 5 && j < s.length(); j++) {
				x = x * 10 + (s[j] - '0');
				if (prime[x]) mx = max(mx, x);
			}
		}

		cout << mx << '\n';
	}
}