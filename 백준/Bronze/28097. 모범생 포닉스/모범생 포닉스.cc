#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int time = 0;
	time += (n - 1) * 8;
	while (n--) {
		int k;
		cin >> k;
		time += k;
	}

	cout << time / 24 << ' ' << time % 24;
}