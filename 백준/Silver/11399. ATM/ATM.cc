#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	vector<int> K;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		K.push_back(tmp);
	}

	sort(K.begin(), K.end());
	int wait = 0, all = 0;
	for (int i = 0; i < N; i++) {
		wait += K[i];
		all += wait;
	}

	cout << all;
}