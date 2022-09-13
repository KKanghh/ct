#include <bits/stdc++.h>
using namespace std;
map<int, int> S;
int d[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> d[i];

	int en = 0, mx = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && (!S.count(d[en]) || S[d[en]] < k)) {
			if (!S.count(d[en])) S[d[en]] = 1;
			else if (S[d[en]] < k) S[d[en]]++;
			en++;
		}
		mx = max(mx, en - st);
		S[d[st]]--;
		if (S[d[st]] == 0) S.erase(S[d[st]]);
	}

	cout << mx;
}