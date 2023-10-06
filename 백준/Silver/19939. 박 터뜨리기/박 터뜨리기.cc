#include <bits/stdc++.h>
using namespace std;
int sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= k; i++) sum += i;

  if (n < sum) {
    cout << -1;
    return 0;
  }

  while (n > sum) {
    sum += k;
  }

  if (n == sum) cout << k - 1;
  else cout << k;
}