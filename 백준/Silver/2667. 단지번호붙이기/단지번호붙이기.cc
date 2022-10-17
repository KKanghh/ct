#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[25][25];
bool vis[25][25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	vector<int> V;
	int dx[4] = { 1, 0 ,-1, 0 };
	int dy[4] = { 0, -1, 0 ,1 };

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			board[i][j] = input[j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				int size = 1;
				cnt++;
				vis[i][j] = true;
				Q.push({ i, j });

				while (!Q.empty()) {
					pair<int, int> temp = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = temp.X + dx[k];
						int ny = temp.Y + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						vis[nx][ny] = true;
						Q.push({ nx, ny });
						size++;
					}
				}

				V.push_back(size);
			}
		}
	}

	cout << cnt << '\n';
	sort(V.begin(), V.end());
	for (auto e : V) {
		cout << e << '\n';
	}
}