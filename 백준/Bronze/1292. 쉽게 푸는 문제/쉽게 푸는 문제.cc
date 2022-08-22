#include <bits/stdc++.h>
using namespace std;

int D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int j = 1, cnt = j;
	for (int i = 1; i <= 1000; i++) {
		D[i] = j;
		cnt--;
		if (cnt == 0) {
			j++;
			cnt = j;
		}
	}

	int a, b;
	cin >> a >> b;

	int res = 0;
	for (int i = a; i <= b; i++) {
		res += D[i];
	}
	cout << res;
}