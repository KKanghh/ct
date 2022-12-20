#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int>> S;
vector<int> A;
int F[1000001], ans[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		A.push_back(t);
		F[t]++;
	}

	S.push({ F[A[0]], 0 });

	for (int i = 1; i < n; i++) {
		while (!S.empty() && S.top().first < F[A[i]]) {
			ans[S.top().second] = A[i];
			S.pop();
		}
		S.push({ F[A[i]], i });
	}

	for (int i = 0; i < n; i++) cout << (ans[i] == 0 ? -1 : ans[i]) << ' ';
}