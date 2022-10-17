#include <bits/stdc++.h>
using namespace std;
int num[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	num[0] = 1;
	for (int i = 1; i < 11; i++) {
		num[i] = i * num[i - 1];
	}
	int N, K;
	cin >> N >> K;

	cout << num[N] / num[K] / num[N - K];
}