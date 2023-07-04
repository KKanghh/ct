#include <bits/stdc++.h>
using namespace std;
char board[20][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mx, r, c, cnt;
bool check[26];

void dfs(int x, int y) {
  check[board[x][y] - 'A'] = true;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (check[board[nx][ny] - 'A']) continue;
    cnt++;
    dfs(nx, ny);
    cnt--;
  }
  mx = max(mx, cnt + 1);
  check[board[x][y] - 'A'] = false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0, 0);


  cout << mx;

}