#include <bits/stdc++.h>
using namespace std;
int D[100];
deque<int> k;

int gcd(int a, int b) {
	while (a != 0 && b != 0) {
		int tmp;
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> D[i];
	sort(D, D + n);
	for (int i = 0; i < n - 1; i++) {
		k.push_back(D[i + 1] - D[i]);
	}
	while (k.size() > 1) {
		int a, b;
		a = k.front();
		k.pop_front();
		b = k.front();
		k.pop_front();
		k.push_front(gcd(a, b));
	}
	vector<int> ans;
	for (int i = 2; i * i <= k[0]; i++) {
		if (k[0] % i == 0) ans.push_back(i);
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] * ans[i] == k[0]) continue;
		ans.push_back(k[0] / ans[i]);
	}

	for (int e : ans) cout << e << ' ';
	cout << k[0];
}