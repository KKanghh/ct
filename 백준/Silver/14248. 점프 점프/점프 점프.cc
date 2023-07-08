#include <bits/stdc++.h>
using namespace std;

int D[100001], num[100001], n, cnt;

void dfs(int k) {
  if (k <= 0 || k > n || D[k] > 0) return;

  D[k] = 1;
  cnt++;
  dfs(k - num[k]);
  dfs(k + num[k]);

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) cin >> num[i];

  int k;
  cin >> k;

  dfs(k);

  cout << cnt;
}