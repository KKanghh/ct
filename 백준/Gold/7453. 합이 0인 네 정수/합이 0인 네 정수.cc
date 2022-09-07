#include <bits/stdc++.h>
using namespace std;
int A[4000], B[4000], C[4000], D[4000];
vector<int> one, two;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			one.push_back(A[i] + B[j]);
			two.push_back(C[i] + D[j]);
		}
	}

	sort(two.begin(), two.end());
	long long cnt = 0;
	for (int e : one) {
		cnt += (upper_bound(two.begin(), two.end(), -e) - lower_bound(two.begin(), two.end(), -e));
	}

	cout << cnt;
}