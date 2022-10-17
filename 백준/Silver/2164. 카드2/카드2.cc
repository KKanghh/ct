#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;

	int num;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		Q.push(i);
	}

	while (Q.size() > 1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}

	cout << Q.front();
}