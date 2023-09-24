#include <bits/stdc++.h>
using namespace std;
int n;
char board[50][50];
int mx;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int check() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    char flag = ' ';
    int score = 0;
    for (int j = 0; j < n; j++) {
      if (board[i][j] == flag) {
        score++;
      }
      else {
        score = 1;
        flag = board[i][j];
      }
      cnt = max(cnt, score);
    }
  }

  for (int j = 0; j < n; j++) {
    char flag = ' ';
    int score = 0;
    for (int i = 0; i < n; i++) {
      if (board[i][j] == flag) {
        score++;
      }
      else {
        score = 1;
        flag = board[i][j];
      }
      cnt = max(cnt, score);
    }
  }

  return cnt;
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

  mx = check();

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int dir = 0; dir < 2; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx >= n || ny >= n) continue;
        if (board[x][y] == board[nx][ny]) continue;

        swap(board[x][y], board[nx][ny]);
        mx = max(mx , check());
        swap(board[x][y], board[nx][ny]);
      }
    }
  }

  cout << mx;
}