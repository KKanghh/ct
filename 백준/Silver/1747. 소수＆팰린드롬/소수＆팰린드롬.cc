#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(5000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	prime[1] = false;
	
	for (int i = 2; i * i <= 5000000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 5000000; j += i) {
				prime[j] = false;
			}
		}
	}


	int n;
	cin >> n;
	

	for (int i = n; i <= 5000000; i++) {
		if (prime[i]) {
			string s;
			int t = i;
			while (t > 0) {
				s.push_back(t % 10 + '0');
				t /= 10;
			}
			string k = s;
			reverse(s.begin(), s.end());
			if (s == k) {
				cout << k;
				break;
			}
		}
	}

}