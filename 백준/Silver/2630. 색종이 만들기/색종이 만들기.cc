#include <bits/stdc++.h>
using namespace std;
int board[128][128];
int n, cnt_b, cnt_w;

void dfs(int sx, int sy, int ex, int ey) {
  int flag = board[sx][sy];
  bool one = true;
  for (int i = sx; i < ex; i++) {
    for (int j = sy; j < ey; j++) {
      one = one && flag == board[i][j];
    }
  }

  if (one) {
    if (flag) cnt_b++;
    else cnt_w++;
    return;
  }

  dfs(sx, sy, (sx + ex) / 2, (sy + ey) / 2);
  dfs((sx + ex) / 2, sy, ex, (sy + ey) / 2);
  dfs(sx, (sy + ey) / 2, (sx + ex) / 2, ey);
  dfs((sx + ex) / 2, (sy + ey) / 2, ex, ey);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n; j++) cin >> board[i][j];
  }

  dfs(0, 0, n, n);

  cout << cnt_w << '\n' << cnt_b;
}