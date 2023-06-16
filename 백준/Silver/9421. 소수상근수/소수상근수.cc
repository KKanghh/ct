#include <bits/stdc++.h>
using namespace std;
int DP[1000001];
vector<bool> prime(1000001, true);

int dfs(int n) {
  if (DP[n] == -1) {
    int k = 0, t = n;
    while (t > 0) {
      int p = t % 10;
      k += p * p;
      t /= 10;
    }
    if (k == 1) {
      return DP[n] = true;
    }
    else {
      DP[n] = false;
      return DP[n] = dfs(k);
    }
  }
  else return DP[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  fill(DP, DP + 1000001, -1);
  DP[1] = true;
  prime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dfs(i) && prime[i]) cout << i << '\n';
  }

}