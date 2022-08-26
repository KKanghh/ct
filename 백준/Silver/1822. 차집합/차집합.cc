#include <bits/stdc++.h>
using namespace std;
int A[500000], B[500000];
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	
	for (int i = 0; i < a; i++) cin >> A[i];
	sort(A, A + a);
	for (int i = 0; i < b; i++) cin >> B[i];
	sort(B, B + b);

	for (int i = 0; i < a; i++) {
		if (!binary_search(B, B + b, A[i])) ans.push_back(A[i]);
	}

	cout << ans.size() << '\n';
	for (int k : ans) cout << k << ' ';
}