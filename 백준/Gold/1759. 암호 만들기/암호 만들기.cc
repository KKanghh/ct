#include <bits/stdc++.h>
using namespace std;
char h[15], arr[15];
int selected[15];
int l, c;

void func(int k, int m, int j, int t) {
	if (k == l) {
		if (m >= 1 && j >= 2) {
			for (int i = 0; i < l; i++) cout << arr[i];
			cout << '\n';
		}
		return;
	}
	for (int i = t; i < c; i++) {
		arr[k] = h[i];
		if (h[i] == 'a' || h[i] == 'e' || h[i] == 'i' || h[i] == 'o' || h[i] == 'u') func(k + 1, m + 1, j, i + 1);
		else func(k + 1, m, j + 1, i + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> h[i];
	sort(h, h + c);
	func(0, 0, 0, 0);
}