#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(arr, arr + 9, 1);
	cin >> n >> m;
	for (int i = 0; i < m; i++) arr[i] = 0;
	do {
		for (int i = 0; i < n; i++) if (arr[i] == 0) cout << i + 1 << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr + n));
}