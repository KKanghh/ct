#include <bits/stdc++.h>
using namespace std;
int a[100000];
int st, en;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, mn = 0x7fffffff;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	while (st < n && en < n) {
		while (en < n && a[st] + m > a[en]) en++;
		if (en < n && a[en] - a[st] >= m) mn = min(mn, a[en] - a[st]);
		st++;
	}

	cout << mn;

}