#include <bits/stdc++.h>
using namespace std;
int ans[20000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		ans[temp + 10000000]++;
	}

	cin >> num;

	while (num--) {
		int temp;
		cin >> temp;
		cout << ans[temp + 10000000] << ' ';
	}
}