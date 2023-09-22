#include <bits/stdc++.h>
using namespace std;
int D[101][100001];
int walk[101][2];
int bike[101][2];
int mn;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) cin >> walk[i][0] >> walk[i][1] >> bike[i][0] >> bike[i][1];

  for (int i = 1; i <= n; i++) {
    for (int j = walk[i][0]; j <= k; j++) {
      if (j - walk[i][0] < mn) continue;
      D[i][j] = max(D[i][j], D[i - 1][j - walk[i][0]] + walk[i][1]);
    }

    for (int j = bike[i][0]; j <= k; j++) {
      if (j - bike[i][0] < mn) continue;
      D[i][j] = max(D[i][j], D[i - 1][j - bike[i][0]] + bike[i][1]);
    }

    mn += min(bike[i][0], walk[i][0]);
  }

  cout << D[n][k];

}