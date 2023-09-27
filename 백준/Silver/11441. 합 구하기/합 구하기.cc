#include <bits/stdc++.h>
using namespace std;
int D[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    D[i] = D[i - 1] + k;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << D[b] - D[a - 1] << '\n';
  }

}