#include <bits/stdc++.h>
using namespace std;
int choose[100];
int gcd(int a, int b) {
	int tmp;
	while (a > 0 && b > 0) {
		tmp = b;
		a %= b;
		b = a;
		a = tmp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		long long cnt = 0;
		cin >> n;
		fill(choose, choose + 100, 1);
		fill(choose, choose + 2, 0);
		vector<int> k;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			k.push_back(tmp);
		}
		do {
			int a = -1, b = -1;
			for (int i = 0; i < n; i++) {
				if (choose[i] == 0) {
					if (a == -1) a = i;
					else b = i;
				}
			}
			cnt += gcd(k[a], k[b]);
		} while (next_permutation(choose, choose + n));
		cout << cnt << '\n';
	}
	

}