#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long x, y;
  cin >> x >> y;

  long long z = y * 100 / x;

  if (z >= 99) {
    cout << -1;
    return 0;
  }

  long long st = 0, en = 1e9;
  while (st < en) {
    long long mid = (st + en) / 2;

    if ((y + mid) * 100 / (x + mid) == z) st = mid + 1;
    else en = mid;
  }
  cout << st;
}