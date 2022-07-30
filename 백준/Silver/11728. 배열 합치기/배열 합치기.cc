#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector<int> A, B, C;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}

	int i = 0, j = 0;

	while (i < n && j < m) {
		if (A[i] < B[j]) C.push_back(A[i++]);
		else C.push_back(B[j++]);
	}

	while (i < n) C.push_back(A[i++]);
	while (j < m) C.push_back(B[j++]);

	for (int k : C) cout << k << ' ';
}