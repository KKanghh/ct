#include <bits/stdc++.h>
using namespace std;
map<char, int> ms;
int price[16];
string t, title[16];
int cnt, sum, mn = 0x3f3f3f3f, n;

void dfs(int k) {
  if (cnt == t.size()) {
    mn = min(mn, sum);
    return;
  }

  for (int i = k; i < n; i++) {
    string S;
    for (int j = 0; j < title[i].size(); j++) {
      if (ms.count(title[i][j]) && ms[title[i][j]] > 0) {
        S.push_back(title[i][j]);
        ms[title[i][j]]--;
        cnt++;
      }
    }
    
    if (S.size() > 0) {
      sum += price[i];
      dfs(i + 1);
      for (char e: S) {
        ms[e]++;
        cnt--;
      }
      sum -= price[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    if (ms.count(t[i])) ms[t[i]]++;
    else ms[t[i]] = 1;
  }

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> price[i] >> title[i];

  dfs(0);

  if (mn == 0x3f3f3f3f) cout << -1;
  else cout << mn;
}