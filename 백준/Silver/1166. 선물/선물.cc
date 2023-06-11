#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double n, l, w, h;
	cin >> n >> l >> w >> h;

	double st = 0.0, en = 1e9;

	for (int i = 0; i < 10000; i++) {
		double mid = (st + en) / 2.0;
		if ((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid) >= n) st = mid;
		else en = mid - 1e-10;
	}

	printf("%0.10f", st);
}