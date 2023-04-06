#include<bits/stdc++.h>
using namespace std;
set<int> D[21];
int num[4] = { 1, 5, 10, 50 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	D[0].insert(0);

	for (int i = 1; i <= n; i++) {
		for (int a : D[i - 1]) {
			for (int b : num) {
				D[i].insert(a + b);
			}
		}
	}

	cout << D[n].size();
}