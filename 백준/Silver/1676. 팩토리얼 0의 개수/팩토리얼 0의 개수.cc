#include <bits/stdc++.h>
using namespace std;
int fact[501];
int N;

int main() {
	cin >> N;
	fact[0] = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = i, k = 0;
		while (tmp % 5 == 0) {
			k++;
			tmp /= 5;
		}
		fact[i] = fact[i - 1] + k;
	}

	cout << fact[N];
}