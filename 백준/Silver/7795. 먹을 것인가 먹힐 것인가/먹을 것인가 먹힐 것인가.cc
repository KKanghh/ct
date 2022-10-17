#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		vector<int> A, B;
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			int tmp;
			cin >> tmp;
			A.push_back(tmp);
		}
		for (int i = 0; i < b; i++) {
			int tmp;
			cin >> tmp;
			B.push_back(tmp);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int cnt = 0;
		int x = 0;
		for (int e : B) {
			while (x < a && A[x] <= e) x++;
			cnt += a - x;
		}
		cout << cnt << '\n';
	}
}