#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> D;

	int size;
	cin >> size;

	for (int i = 1; i <= size; i++) {
		D.push_back(i);
	}

	int num, cnt = 0, last = 1;
	cin >> num;

	while (num--) {
		int temp;
		cin >> temp;
		int i = 0;

		while (D[i] != temp) i++;
			
		if (i > D.size() / 2) {
			while (D.front() != temp) {
				D.push_front(D.back());
				D.pop_back();
				cnt++;
			}
		}
		else {
			while (D.front() != temp) {
				D.push_back(D.front());
				D.pop_front();
				cnt++;
			}
		}
		D.pop_front();
	}

	cout << cnt;
}