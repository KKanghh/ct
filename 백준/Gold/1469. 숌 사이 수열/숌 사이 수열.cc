#include <bits/stdc++.h>
using namespace std;
int D[16], k[8], n;
bool ans;
int cnt[16];

bool isCntBig() {
  for (int i = 0; i < 2 * n; i++) {
    if (cnt[i] == D[i]) continue;

    return cnt[i] > D[i];
  }

  return true;
}

void func(int a) {
  if (a == n) {
    if (isCntBig()) {
      for (int i = 0; i < 2 * n; i++) cnt[i] = D[i];
    }
    return;
  }

  for (int i = 0; i + k[a] + 1 < 2 * n; i++) {
    if (D[i] != -1 || D[i + k[a] + 1] != -1) continue;
    D[i] = k[a];
    D[i + k[a] + 1] = k[a];
    func(a + 1);
    D[i] = -1;
    D[i + k[a] + 1] = -1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) cin >> k[i];
  fill(D, D + 2 * n, -1);
  fill(cnt, cnt + 2 * n, 17);

  func(0);

  if (cnt[0] < 17) {
    for (int i = 0; i < 2 * n; i++) cout << cnt[i] << ' ';
  }
  else cout << -1;
}