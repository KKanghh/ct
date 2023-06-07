#include <bits/stdc++.h>
using namespace std;
int score[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> score[i];

	int st = 0, en = 2000000;

	while (st < en) {
		int mid = (st + en + 1) / 2;

		int cnt = 0;
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += score[i];
			if (s >= mid) {
				cnt++;
				s = 0;
			}
		}

		if (cnt >= k) st = mid;
		else en = mid - 1;

	}

	cout << st;
}