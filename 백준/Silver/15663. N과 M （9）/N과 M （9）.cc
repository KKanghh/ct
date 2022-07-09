#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m, num[9];
short cnt[10001];
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[num[i]] && tmp != num[i]) {
			arr[k] = num[i];
			cnt[num[i]]--;
			tmp = num[i];
			func(k + 1);
			cnt[num[i]]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		cnt[num[i]]++;
	}
	sort(num, num + n);
	func(0);
}