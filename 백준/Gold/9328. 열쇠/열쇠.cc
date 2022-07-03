#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[100][100];
bool vis[100][100];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int h, w, cnt = 0;
		bool keys[26] = {};
		vector<pair<int, int>> doors[26];
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		
		string key;
		cin >> key;
		for (char e : key) {
			if (e == '0') break;
			keys[e - 'a'] = true;
		}

		for (int i = 0; i < h; i++) {
			if (board[i][0] != '*' && !vis[i][0]) {
				if (board[i][0] == '.' || board[i][0] == '$') {
					vis[i][0] = true;
					Q.push({ i, 0 });
				}
				else if (board[i][0] >= 'A' && board[i][0] <= 'Z') {
					if (keys[board[i][0] - 'A']) {
						vis[i][0] = true;
						Q.push({ i, 0 });
					}
					else {
						doors[board[i][0] - 'A'].push_back({ i, 0 });
					}
				}
				else if (board[i][0] >= 'a' && board[i][0] <= 'z') {
					vis[i][0] = true;
					Q.push({ i, 0 });
				}
			}
			if (board[i][w - 1] != '*' && !vis[i][w - 1]) {
				if (board[i][w - 1] == '.' || board[i][w - 1] == '$') {
					vis[i][w - 1] = true;
					Q.push({ i, w - 1 });
				}
				else if (board[i][w - 1] >= 'A' && board[i][w - 1] <= 'Z') {
					if (keys[board[i][w - 1] - 'A']) {
						vis[i][w - 1] = true;
						Q.push({ i, w - 1 });
					}
					else {
						doors[board[i][w - 1] - 'A'].push_back({ i, w - 1 });
					}
				}
				else if (board[i][w - 1] >= 'a' && board[i][w - 1] <= 'z') {
					vis[i][w - 1] = true;
					Q.push({ i, w - 1 });
				}
			}
		}
		for (int i = 0; i < w; i++) {
			if (board[0][i] != '*' && !vis[0][i]) {
				if (board[0][i] == '.' || board[0][i] == '$') {
					vis[0][i] = true;
					Q.push({ 0, i });
				}
				else if (board[0][i] >= 'A' && board[0][i] <= 'Z') {
					if (keys[board[0][i] - 'A']) {
						vis[0][i] = true;
						Q.push({ 0, i });
					}
					else {
						doors[board[0][i] - 'A'].push_back({ 0, i });
					}
				}
				else if (board[0][i] >= 'a' && board[0][i] <= 'z') {
					vis[0][i] = true;
					Q.push({ 0, i });
				}
			}
			if (board[h - 1][i] != '*' && !vis[h - 1][i]) {
				if (board[h - 1][i] == '.' || board[h - 1][i] == '$') {
					vis[h - 1][i] = true;
					Q.push({ h - 1, i });
				}
				else if (board[h - 1][i] >= 'A' && board[h - 1][i] <= 'Z') {
					if (keys[board[h - 1][i] - 'A']) {
						vis[h - 1][i] = true;
						Q.push({ h - 1, i });
					}
					else {
						doors[board[h - 1][i] - 'A'].push_back({ h - 1, i });
					}
				}
				else if (board[h - 1][i] >= 'a' && board[h - 1][i] <= 'z') {
					vis[h - 1][i] = true;
					Q.push({ h - 1, i });
				}
			}
		}

		while (!Q.empty()) {	
			auto a = Q.front();
			Q.pop();
			//cout << a.X << ' ' << a.Y << ' ' << board[a.X][a.Y] << '\n';
			if (board[a.X][a.Y] >= 'a' && board[a.X][a.Y] <= 'z') {
				if (!keys[board[a.X][a.Y] - 'a']) {
					for (auto e : doors[board[a.X][a.Y] - 'a']) {
						vis[e.X][e.Y] = true;
						Q.push({ e.X, e.Y });
					}
				}
				keys[board[a.X][a.Y] - 'a'] = true;
			}
			if (board[a.X][a.Y] == '$') cnt++;
			for (int i = 0; i < 4; i++) {
				int nx = a.X + dx[i];
				int ny = a.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '*' || vis[nx][ny] == true) continue;
				if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
					if (keys[board[nx][ny] - 'A']) {
						Q.push({ nx, ny });
						vis[nx][ny] = true;
					}
					else {
						doors[board[nx][ny] - 'A'].push_back({ nx, ny });
					}
					continue;
				}
				
				vis[nx][ny] = true;
				Q.push({ nx, ny });
			}
		}
		cout << cnt << '\n';

		for (int i = 0; i < h; i++) {
			fill(vis[i], vis[i] + w, false);
		}
	}
}