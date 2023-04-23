#include <bits/stdc++.h>
using namespace std;

int D[1001];
string S;
vector<string> A;
vector<int> X;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string t;
		int k;
		cin >> t >> k;
		A.push_back(t);
		X.push_back(k);
	}

	for (int i = 1; i <= S.size(); i++) {
		D[i] = D[i - 1] + 1;
		for (int j = 0; j < m; j++) {
			if (i < A[j].size()) continue;

			if (S.substr(i - A[j].size(), A[j].size()) == A[j]) {
				D[i] = max(D[i - A[j].size()] + X[j], D[i]);
			}
		}
	}

	cout << D[S.size()];

}