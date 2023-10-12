#include <bits/stdc++.h>
using namespace std;
map<string, int> M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    string name = s.substr(s.find('.') + 1, s.size());

    if (M.count(name)) M[name]++;
    else M[name] = 1;
  }

  for (auto e: M) {
    cout << e.first << ' ' << e.second << '\n';
  }
}