#include <bits/stdc++.h>
using namespace std;
vector<long long> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		long long k = 0;
		while (tmp > 0) {
			k = k * 10 + tmp % 10;
			tmp /= 10;
		}
		V.push_back(k);
	}

	sort(V.begin(), V.end());
	for (long long e : V) cout << e << '\n';
}