#include <bits/stdc++.h>
using namespace std;
vector<bool> D(4000001, true);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	D[0] = false;
	D[1] = false;
	for (int i = 2; i * i < 4000001; i++) {
		if (D[i]) {
			for (int j = i * i; j < 4000001; j += i) {
				D[j] = false;
			}
		}
	}

	int en = 2, sum = 2, cnt = 0;
	for (int st = 2; st < 4000001; st++) {
		if (!D[st]) continue;
		while (en < 4000001 && sum < n) {
			en++;
			if (en < 4000001 && D[en]) sum += en;
		}
		if (n == sum) cnt++;
		sum -= st;
	}

	cout << cnt;
}