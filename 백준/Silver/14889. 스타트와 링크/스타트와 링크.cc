#include <bits/stdc++.h>
using namespace std;
int board[20][20];
bool team[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, mn = 0x7f7f7f7f;
	cin >> n;
	fill(team + n / 2, team + n, true);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	do {
		vector<int> teamA, teamB;
		int A = 0, B = 0;

		for (int i = 0; i < n; i++) {
			if (team[i]) teamA.push_back(i);
			else teamB.push_back(i);
		}

		for (int e : teamA) {
			for (int t : teamA) {
				A += board[e][t];
			}
		}

		for (int e : teamB) {
			for (int t : teamB) {
				B += board[e][t];
			}
		}

		int diff = abs(A - B);
		mn = min(diff, mn);
	} while (next_permutation(team, team + n));

	cout << mn;
}