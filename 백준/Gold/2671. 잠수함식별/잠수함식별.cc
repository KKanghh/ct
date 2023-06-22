#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int cur = 0;
  bool ps = false;

  while (cur < s.size()) {
    if (s[cur] == '1') {
      cur++;
      if (s[cur] == '1') {
        cout << "NOISE";
        return 0;
      }
      cur++;
      if (s[cur] == '1') {
        cout << "NOISE";
        return 0;
      }
      while (cur < s.size() && s[cur] == '0') cur++;
      if (cur >= s.size() || s[cur] != '1') {
        cout << "NOISE";
        return 0;
      }
      else cur++;
      while (cur < s.size() && s[cur] == '1') {
        cur++;
        ps = true;
      }
    }
    else {
      if (cur + 1 < s.size() && s[cur + 1] == '1') cur += 2;
      else if (cur > 0 && cur + 1 < s.size() && s[cur + 1] == '0' && ps) {
        ps = false;
        cur--;
      }
      else {
        cout << "NOISE";
        return 0;
      }
    }
  }


  cout << "SUBMARINE";
}