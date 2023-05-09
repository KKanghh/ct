#include <bits/stdc++.h>
using namespace std;
string ans, s;
int n;

void dfs(int k) {
	
	for (int i = 1; i <= k / 2; i++) {
		if (ans.substr(k - 2 * i, i) == ans.substr(k - i, i)) return;
	}
	if (k == n) {
		s = ans;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		ans.push_back('0' + i);
		dfs(k + 1);
		if (s.size() > 0) return;
		ans.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dfs(0);
	cout << s;

}