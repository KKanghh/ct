#include <bits/stdc++.h>
using namespace std;
queue<string> Q;
string s, t;

bool bfs() {
  Q.push(t);
  while (!Q.empty()) {
    string k = Q.front();
    Q.pop();
    if (k.size() < s.size()) continue;
    if (k == s) return true;
    if (k[k.size() - 1] == 'A') {
      string p = k;
      p.pop_back();
      Q.push(p);
    }
    if (k[0] == 'B') {
      reverse(k.begin(), k.end());
      k.pop_back();
      Q.push(k);
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;

  Q.push(t);

  cout << bfs();
}