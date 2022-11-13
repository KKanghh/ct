#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int score = 0;
	for (int i = 0; i < 5; i++) {
		int k;
		cin >> k;
		score += k;
	}
	cout << score;
}