#include <bits/stdc++.h>
using namespace std;
int N[100000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> N[i];

  long long cnt = 0;

  sort(N, N + n, greater<int> ());

  for (int i = 0; i < n; i++) {
    cnt += max(N[i] - i, 0);
  }

  cout << cnt;
}