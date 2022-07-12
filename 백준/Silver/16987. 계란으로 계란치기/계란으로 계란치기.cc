#include <bits/stdc++.h>
using namespace std;
int S[8], W[8], cnt, N;

void func(int k) {
	if (k == N) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] <= 0) tmp++;
		}
		cnt = max(cnt, tmp);
		return;
	}
	if (S[k] <= 0) {
		func(k + 1);
		return;
	}
	bool noegg = true;
	for (int i = 0; i < N; i++) {
		if (S[i] <= 0) continue;
		if (i == k) continue;
		S[i] -= W[k];
		S[k] -= W[i];
		noegg = false;
		func(k + 1);
		S[i] += W[k];
		S[k] += W[i];
	}
	if (noegg) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] <= 0) tmp++;
		}
		cnt = max(cnt, tmp);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}

	func(0);
	cout << cnt;
}