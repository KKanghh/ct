#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	cout << (n1 + 1) * (n2 + 1) / (n3 + 1) - 1;
}