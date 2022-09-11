#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int cnt = 1;
	while (b > a) {
		if (b % 2 == 0) {
			b /= 2;
			cnt++;
			continue;
		}
		else if (b % 10 == 1) {
			b /= 10;
			cnt++;
			continue;
		}
		break;
	}

	if (a == b) cout << cnt;
	else cout << -1;
}