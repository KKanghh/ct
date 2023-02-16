#include <bits/stdc++.h>
using namespace std;
int num[2000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	int cnt = 0;
	for (int i = 0; i <= ((n - 1) / 2); i++) {
		int j = 2;
		int k = 0;
		while (j <= num[i]) {
			j *= 2;
			k++;
		}
		cnt += k;
	}

	cout << cnt + 1;
}