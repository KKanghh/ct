#include <bits/stdc++.h>
using namespace std;
int board[10][10];
bool vis[10][10];
int n, flower, cnt, mn = 0x3f3f3f3f;

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

void dfs(int x, int y) {
  if (flower == 3) {
    mn = min(cnt, mn);
    return;
  }

  for (int i = x; i < n - 1; i++) {
    for (int j = x == i ? y : 1; j < n - 1; j++) {
      bool ps = false;
      for (int dir = 0; dir < 5; dir++) {
        ps = ps || vis[i + dx[dir]][j + dy[dir]];
      }
      if (ps) continue;

      for (int dir = 0; dir < 5; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        cnt += board[nx][ny];
        vis[nx][ny] = true;
      }
      flower++;
      dfs(i, j);
      flower--;
      for (int dir = 0; dir < 5; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        cnt -= board[nx][ny];
        vis[nx][ny] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  dfs(1, 1);

  cout << mn;
}