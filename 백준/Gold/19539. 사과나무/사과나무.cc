#include <bits/stdc++.h>
using namespace std;
int D[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int one = 0, two = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> D[i];

	sort(D, D + n);

	for (int i = 0; i < n; i++) {
		while (two > 0 && D[i] > 1) {
			D[i] -= 2;
			two--;
		}
		while (one > 0 && D[i] > 0) {
			D[i] -= 1;
			one--;
		}
		D[i] %= 3;
		if (D[i] == 1) two++;
		if (D[i] == 2) one++;
	}
	if (one || two) cout << "NO";
	else cout << "YES";
}