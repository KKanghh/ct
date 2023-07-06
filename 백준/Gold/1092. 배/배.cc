#include <bits/stdc++.h>
using namespace std;
int crane[50];
int box[10000];
bool vis[10000];
int tik;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> crane[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> box[i];

    sort(box, box + m);

  while (m > 0) {
    int cnt = 0;
    tik++;
    for (int i = 0; i < n; i++) {
      int k = upper_bound(box, box + m, crane[i]) - box;
      if (k == 0) continue;
      cnt++;
      box[k - 1] = 1000001;
      sort(box, box + m);
      m--;
    }

    if (cnt == 0) {
      cout << -1;
      return 0;
    }
  }

  cout << tik;

}