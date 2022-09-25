#include <bits/stdc++.h>
using namespace std;
int A[1001], D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		D[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) D[i] = max(D[i], D[j] + 1);
		}
	}

	cout << *max_element(D + 1, D + n + 1);
	
}