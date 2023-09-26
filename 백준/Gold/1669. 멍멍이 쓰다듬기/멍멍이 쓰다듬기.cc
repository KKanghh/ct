#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y;
  cin >> x >> y;

  int t = y - x;

  int cnt = 0;
  int l = 1;

  while (t > 0) {
    if (t <= l) {
      cnt++;
      t -= l;
    }
    else {
      cnt += 2;
      t -= 2 * l;
    }
    l++;
  }

  cout << cnt;
}