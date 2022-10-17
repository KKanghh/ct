#include <bits/stdc++.h>
using namespace std;
int D[8001];
vector<int> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s = 4000, l = -4000;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		sum += tmp;
		D[tmp + 4000]++;
		s = min(s, tmp);
		l = max(l, tmp);
	}
	cout << (int)round(sum / n) << '\n';
	sort(a.begin(), a.end());
	cout << a[n / 2] << '\n';
	int mx = 0;
	int cur = 0;
	int cnt = 0;
	for (int i = s + 4000; i <= l + 4000; i++) {
		if (D[i] > mx) {
			cnt = 0;
			mx = D[i];
			cur = i;
		}
		else if (D[i] == mx) {
			cnt++;
			if (cnt == 1) cur = i;
		}
	}

	cout << cur - 4000 << '\n';
	cout << l - s;
}