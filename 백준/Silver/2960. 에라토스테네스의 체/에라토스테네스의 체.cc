#include <bits/stdc++.h>
using namespace std;
vector<bool> D(1001, true);

int main() {
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (D[i]) {
			cnt++;
			if (cnt == k) {
				cout << i;
				return 0;
			}
			for (int j = i + i; j <= n; j += i) {
				if (D[j]) {
					D[j] = false;
					cnt++;
					if (cnt == k) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}
}