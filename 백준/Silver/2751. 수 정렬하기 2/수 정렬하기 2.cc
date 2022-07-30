#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<int> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < n; i++) cout << V[i] << '\n';
}