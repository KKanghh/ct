#include <bits/stdc++.h>
using namespace std;
//int card[1000];
priority_queue<long long, vector<long long>, greater<long long>> card;
int main() {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		card.push(tmp);
	}

	for (int i = 0; i < m; i++) {
		//sort(card, card + n);
		long long k = 0;
		k += card.top();
		card.pop();
		k += card.top();
		card.pop();
		card.push(k);
		card.push(k);
	}

	long long num = 0;
	for (int i = 0; i < n; i++) {
		num += card.top();
		card.pop();
	}
	cout << num;
}