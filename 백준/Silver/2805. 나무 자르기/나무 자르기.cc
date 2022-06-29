#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> V;
	int N, M;
	cin >> N >> M;
	int largest = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
		if (tmp > largest) largest = tmp;
	}

	int i = 0, j = largest;
	while (i + 1 < j) {
		int mid = (i + j) / 2;
		long long cut = 0;
		for (auto e : V) {
			cut += e - mid > 0 ? e - mid : 0;
		}
		if (cut >= M) i = mid;
		else j = mid;
	}

	cout << i;
}