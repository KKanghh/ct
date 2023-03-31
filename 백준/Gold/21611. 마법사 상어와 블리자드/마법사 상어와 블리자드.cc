#include <bits/stdc++.h>
using namespace std;
int board[52][52];
int n, m;
int score[4];

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int mdx[4] = { 0, 1, 0, -1 };
int mdy[4] = { -1, 0, 1, 0 };

queue<int> marble;
queue<pair<int, int>> cnt;

void clean() {
	int head = 0;
	bool vis[52][52] = {false, };
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	vis[x][y] = true;
	while (true) {
		x += mdx[head];
		y += mdy[head];
		if (y == 0) break;
		vis[x][y] = true;
		
		if (board[x][y] > 0) {
			marble.push(board[x][y]);
			board[x][y] = 0;
		}

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}
	}
	x = (n + 1) / 2;
	y = x;

	for (int i = 1; i <= n; i++) {
		fill(vis[i] + 1, vis[i] + n + 1, false);
	}
	head = 0;
	vis[x][y] = true;
	while (!marble.empty()) {
		x += mdx[head];
		y += mdy[head];
		vis[x][y] = true;

		board[x][y] = marble.front();
		marble.pop();

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}
	}
}

bool explode() {
	bool flag = false;
	int x = (n + 1) / 2;
	int y = x;
	bool vis[52][52] = { false, };
	vis[x][y] = true;
	int head = 0;
	int what = board[x][y];
	int howmany = 1;

	while (true) {
		x += mdx[head];
		y += mdy[head];
		if (y == 0) break;
		vis[x][y] = true;
		if (board[x][y] != what) {
			if (what != 0 && howmany < 4) {
				cnt.push({ what, howmany });
			}
			if (howmany >= 4) {
				flag = true;
				score[what] += howmany;
			}
			what = board[x][y];
			howmany = 0;
		}
		howmany++;
		board[x][y] = 0;

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}

	}
	if (what != 0 && howmany < 4) cnt.push({ what, howmany });
	if (what != 0 && howmany >= 4) {
		flag = true;
		score[what] += howmany;
	}
	what = 0;
	howmany = 0;

	for (int i = 1; i <= n; i++) {
		fill(vis[i] + 1, vis[i] + n + 1, false);
	}

	x = (n + 1) / 2;
	y = x;
	head = 0;
	vis[x][y] = true;
	while (!cnt.empty() || howmany > 0) {
		if (howmany == 0) {
			tie(what, howmany) = cnt.front();
			cnt.pop();
		}
		x += mdx[head];
		y += mdy[head];
		vis[x][y] = true;

		board[x][y] = what;
		howmany--;

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}
	}

	return flag;
}

void change() {
	int x = (n + 1) / 2;
	int y = x;
	bool vis[52][52] = { false, };
	vis[x][y] = true;
	int head = 0;
	int what = board[x][y];
	int howmany = 1;

	while (true) {
		x += mdx[head];
		y += mdy[head];
		if (y == 0) break;
		vis[x][y] = true;

		if (board[x][y] != what) {
			if (what > 0) cnt.push({ what, howmany });
			what = board[x][y];
			howmany = 0;
		}
		howmany++;
		board[x][y] = 0;

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}
	}
	if (what > 0) cnt.push({ what, howmany });
	what = 0;
	howmany = 0;
	x = (n + 1) / 2;
	y = x;
	head = 0;
	for (int i = 1; i <= n; i++) fill(vis[i] + 1, vis[i] + n + 1, false);
	vis[x][y] = true;

	while (!cnt.empty() || what > 0 || howmany > 0) {
		if (y == 0) {
			while (!cnt.empty()) cnt.pop();
			break;
		}
		if (what == 0 && howmany == 0) {
			tie(what, howmany) = cnt.front();
			cnt.pop();
		}
		x += mdx[head];
		y += mdy[head];
		vis[x][y] = true;

		if (howmany > 0) {
			board[x][y] = howmany;
			howmany = 0;
		}
		else {
			board[x][y] = what;
			what = 0;
		}

		if (!vis[x + mdx[(head + 1) % 4]][y + mdy[(head + 1) % 4]]) {
			head = (head + 1) % 4;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	while (m--) {
		int d, s;
		cin >> d >> s;
		int x = (n + 1) / 2;
		int y = x;

		for (int i = 1; i <= s; i++) {
			x += dx[d];
			y += dy[d];
			board[x][y] = 0;
		}

		x = (n + 1) / 2;
		y = x;

		clean();
		while (explode());
		change();

	}

	int ans = 0;

	for (int i = 0; i < 4; i++) {
		ans += i * score[i];
	}

	cout << ans;
}