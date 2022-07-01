#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool board[101][101];
bool vis[101][101];
vector<pair<int, int>> V[101][101];
queue<pair<int, int>> Q, fQ;
int cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	while (M--) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		V[x][y].push_back({ nx, ny });
	}

	board[1][1] = true;
	vis[1][1] = true;
	Q.push({ 1, 1 });
	cnt++;

	while (!Q.empty()) {
		auto a = Q.front();
		Q.pop();
		for (auto e : V[a.X][a.Y]) {
			if (board[e.X][e.Y]) continue;
			cnt++;
			board[e.X][e.Y] = true;
			for (int i = 0; i < 4; i++) {
				int nx = e.X + dx[i];
				int ny = e.Y + dy[i];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (vis[nx][ny]) {
					vis[e.X][e.Y] = true;
					Q.push({ e.X, e.Y });
					fQ.push({ e.X, e.Y });
				}
			}
		}
		if (!fQ.empty()) {
			auto b = fQ.front();
			fQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = b.X + dx[i];
				int ny = b.Y + dy[i];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (board[nx][ny] && !vis[nx][ny]) {
					fQ.push({ nx, ny });
					Q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
		}
	}

	cout << cnt;
}