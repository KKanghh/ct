#include <bits/stdc++.h>
using namespace std;
map<string, int> tree;
int cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (getline(cin, s)) {
    if (tree.count(s)) tree[s]++;
    else tree[s] = 1;
    cnt++;
  }
  cout << fixed;
  cout.precision(4);
  for (pair<string, int> e: tree) {
    cout << e.first << ' ' << (double)e.second / (double) cnt * 100 << '\n';
  }
}
