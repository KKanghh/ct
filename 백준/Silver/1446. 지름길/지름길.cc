#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> T;
int n, d;
int cur, no;
int mn = 10000;

void dfs(int k) {
  for (int i = k; i < n; i++) {
    int a, b, c;
    tie(a, b, c) = T[i];
    if (a < cur) continue;
    if (b > d) continue;

    int t = cur;
    cur = b;
    no += b - a - c;
    dfs(i + 1);
    no -= b - a - c;
    cur = t;
  }

  mn = min(mn, d - no);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    T.push_back({a, b, c});
  }

  sort(T.begin(), T.end());

  dfs(0);

  cout << mn;
}