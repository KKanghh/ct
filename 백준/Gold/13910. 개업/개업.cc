#include <bits/stdc++.h>
using namespace std;
int D[20001];
vector<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	fill(D, D + 10001, 0x3f3f3f3f);
	D[0] = 0;

	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;
		S.push_back(s);
		D[s] = 1;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			D[S[i] + S[j]] = 1;
			S.push_back(S[i] + S[j]);
		}
	}

	sort(S.begin(), S.end());

	for (int i = 1; i <= n; i++) {
		for (int s : S) {
			if (s > i) break;
			D[i] = min(D[i], D[i - s] + D[s]);
		}
	}


	if (D[n] == 0x3f3f3f3f) cout << -1;
	else cout << D[n];

}