#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> V;

void hanoi(int a, int b, int c) {
	if (a == 1) {
		V.push_back({ b,c });
		return;
	}

	int d = 6 - b - c;
	hanoi(a - 1, b, d);
	V.push_back({ b, c });
	hanoi(a - 1, d, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	hanoi(n, 1, 3);
	cout << V.size() << '\n';
	for (auto e : V) {
		cout << e.first << ' ' << e.second << '\n';
	}
}
