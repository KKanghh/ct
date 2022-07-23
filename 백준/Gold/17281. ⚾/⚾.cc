#include <bits/stdc++.h>
using namespace std;
int baseball[50][9];
bool base[3];
int out, score, mx = 0;

void clean() {
	for (int i = 0; i < 3; i++) base[i] = false;
}

void play(int num, int inning) {
	switch (baseball[inning][num]) {
	case 0:
		out++;
		break;
	case 1:
		score += base[2];
		base[2] = base[1];
        base[1] = base[0];
        base[0] = true;
		break;
	case 2:
		score += base[2] + base[1];
		base[2] = base[0];
		base[1] = true;
        base[0] = false;
		break;
	case 3:
		score += base[2] + base[1] + base[0];
		base[2] = true;
		base[1] = false;
		base[0] = false;
		break;
	case 4:
		score += base[2] + base[1] + base[0] + 1;
        base[2] = 0;
        base[1] = 0;
        base[0] = 0;
        break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> baseball[i][j];
		}
	}
	int order[8] = {1, 2, 3, 4, 5, 6, 7 ,8 };
	do {
		int now = 0, inning = 0;
		out = 0, score = 0;
		clean();
		while (inning < N) {
			if (now == 3) {
				play(0, inning);
			}
			else if (now < 3) {
				play(order[now], inning);
			}
			else {
				play(order[now - 1], inning);
			}
			if (out == 3) {
				clean();
				out = 0;
				inning++;
			}
			now = (now + 1) % 9;
			if (mx - score > 8 * (3 * N - 3 *inning - out)) break;
		}
		mx = max(score, mx);
	} while (next_permutation(order, order + 8));

	cout << mx;
}