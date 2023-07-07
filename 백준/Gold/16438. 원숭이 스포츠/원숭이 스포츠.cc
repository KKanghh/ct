#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int flag = 1;
  
  for (int i = 0; i < 7; i++) {
    if (flag >= n) flag /= 2;
    for (int j = 1; j <= n; j++) {
      if ((j / flag) % 2) cout << 'B';
      else cout << 'A';
    }
    cout << '\n';
    flag *= 2;
  }
}