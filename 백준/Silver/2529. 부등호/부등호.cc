#include <bits/stdc++.h>
using namespace std;
deque<int> mn, mx;
char b[9];
deque<int> D;
bool p[10];
int n;

void dfs() {
	if (D.size() == n + 1) {
		mn = min(mn, D);
		mx = max(mx, D);
		return;
	}
	if (b[D.size() - 1] == '<') {
		for (int i = D[D.size() - 1] + 1; i <= 9; i++) {
			if (p[i]) continue;
			p[i] = true;
			D.push_back(i);
			dfs();
			D.pop_back();
			p[i] = false;
		}
	}
	else {
		for (int i = D[D.size() - 1] - 1; i >= 0; i--) {
			if (p[i]) continue;
			p[i] = true;
			D.push_back(i);
			dfs();
			D.pop_back();
			p[i] = false;
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i <= n; i++) {
		mn.push_back(9);
		mx.push_back(0);
	}

	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i <= 9; i++) {
		p[i] = true;
		D.push_back(i);
		dfs();
		D.pop_back();
		p[i] = false;
	}

	for (int e : mx) cout << e;
	cout << '\n';
	for (int e : mn) cout << e;
}