#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int cnt;
int D[25];

void dfs(int k) {
  if (k == y - x - 1) dfs(k + 1);
  if (k > n) {
    cnt ++;
    return;
  }
  for (int i = 1; i + k + 1 <= 2 * n; i++) {
    if (D[i] > 0 || D[i + k + 1] > 0) continue;
    D[i] = D[i + k + 1] = k;
    dfs(k + 1);
    D[i] = D[i + k + 1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x >> y;
  D[x] = D[y] = y - x - 1;
  dfs(1);

  cout << cnt;
}