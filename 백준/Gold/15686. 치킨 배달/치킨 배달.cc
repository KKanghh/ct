#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[50][50], N, M;
vector<pair<int, int>> chicken, house;
vector<int> chicken_meter[100];
bool closed[13];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int answer = 0x7fffffff;
	cin >> N >> M;
	fill(closed + M, closed + 13, true);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				house.push_back({ i, j });
			}
			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	
	for (int i = 0; i < house.size(); i++) {
		for (auto h : chicken) {
			int dist = max(house[i].X, h.X) - min(house[i].X, h.X) + max(house[i].Y, h.Y) - min(house[i].Y, h.Y);
			chicken_meter[i].push_back(dist);
		}
	}
	
	do {
		int dist_sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 202;
			for (int j = 0; j < chicken.size(); j++) {
				if (!closed[j]) {
					min_dist = min(chicken_meter[i][j], min_dist);
				}
			}
			dist_sum += min_dist;
		}
		answer = min(dist_sum, answer);
	} while (next_permutation(closed, closed + chicken.size()));

	cout << answer;
}