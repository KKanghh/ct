#include <bits/stdc++.h>
using namespace std;
deque<bool> Topni[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char tmp;
			cin >> tmp;
			Topni[i].push_back(tmp == '1');
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int rotate[4] = {};
		int k;
		cin >> k;
		cin >> rotate[--k];
		int s = k - 1, b = k + 1;
		while (s >= 0) {
			if (Topni[s][2] == Topni[s + 1][6]) break;
			rotate[s] = -rotate[s + 1];
			s--;
		}
		while (b < 4) {
			if (Topni[b][6] == Topni[b - 1][2]) break;
			rotate[b] = -rotate[b - 1];
			b++;
		}
		for (int i = 0; i < 4; i++) {
			if (rotate[i] == 1) {
				Topni[i].push_front(Topni[i].back());
				Topni[i].pop_back();
			}
			else if (rotate[i] == -1) {
				Topni[i].push_back(Topni[i].front());
				Topni[i].pop_front();
			}
		}
	}

	int score = 0;
	for (int i = 0; i < 4; i++) {
		score += Topni[i][0] * (1 << i);
	}

	cout << score;
}