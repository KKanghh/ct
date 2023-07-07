#include <bits/stdc++.h>
using namespace std;
vector<int> D[1000000];

bool isEqual(char a, char b) {
  if (a == 'i' && (b == 'j' || b == 'l')) return true;
  if (a == 'v' && b == 'w') return true;
  if (a == b) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  string submit, answer;
  cin >> submit >> answer;

  for (int i = 0; i <= m; i++) D[0].push_back(i);

  for (int i = 1; i <= n; i++) {
    D[i].push_back(i);
    for (int j = 1; j <= m; j++) {
      if (isEqual(submit[i - 1], answer[j - 1])) {
        D[i].push_back(D[i - 1][j - 1]);
      }
      else {
        D[i].push_back(min({D[i - 1][j - 1], D[i][j - 1], D[i - 1][j]}) + 1);
      }
    }
  }

  cout << D[n][m];
}