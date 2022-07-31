#include <bits/stdc++.h>
using namespace std;
int table[10][10], order[2][20], win[3];
int jiwoo[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int cur[3];

int rsp(int p1, int p2) {
	if (p1 == 0) {
		if (table[jiwoo[cur[0]++]][order[p2 - 1][cur[p2]++]] == 2) return p1;
		else return p2;
	}
	else {
		if (table[order[0][cur[1]++]][order[1][cur[2]++]] == 2) return p1;
		else return p2;
	}
}

int main() {
	int N, K;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
		}
	}

	if (N < K) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < 20; i++) {
		cin >> order[0][i];
	}
	for (int i = 0; i < 20; i++) {
		cin >> order[1][i];
	}
	bool find = false;

	do {
		int p1 = 0;
		int p2 = 1;
		int waiter = 2;
		fill(win, win + 3, 0);
		fill(cur, cur + 3, 0);
		while (true) {
			if (p1 > p2) swap(p1, p2);
			int winner = rsp(p1, p2);
			win[winner]++;
			if (win[winner] == K) {
				if (winner == 0) find = true;
				break;
			}
			if (cur[0] == N) break;
			if (p1 == winner) swap(p2, waiter);
			else swap(p1, waiter);
		}
		if (find) break;
	} while (next_permutation(jiwoo, jiwoo + N));

	if (find) cout << 1;
	else cout << 0;
}