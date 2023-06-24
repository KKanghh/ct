#include <bits/stdc++.h>
using namespace std;
int x[200000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int s, n;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);

    int st = 0;
    int en = 1e9;
    while (st < en) {
      int mid = (st + en + 1) / 2;
      int cnt = 1;
      int flag = x[0];
      for (int i = 1; i < n; i++) {
        if (x[i] - flag >= mid) {
          cnt++;
          flag = x[i];
        }
      }

      if (cnt >= s) st = mid;
      else en = mid - 1;
    }
    cout << st << '\n';
  }

}