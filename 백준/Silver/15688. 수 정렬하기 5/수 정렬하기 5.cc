#include <bits/stdc++.h>
using namespace std;
vector<int> V;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}
	sort(V.begin(), V.end());
	for (int e: V) {
		cout << e << '\n';
	}

}