#include <bits/stdc++.h>
using namespace std;
int D[1000];
string S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	fill(D, D + n, 0x3f3f3f3f);

	D[0] = 0;

	cin >> S;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (S[i] == 'B' && S[j] == 'O' || S[i] == 'O' && S[j] == 'J' || S[i] == 'J' && S[j] == 'B') {
				D[j] = min(D[j], D[i] + (j - i) * (j - i));
			}
		}
	}
	if (D[n - 1] == 0x3f3f3f3f) cout << -1;
	else cout << D[n - 1];
}