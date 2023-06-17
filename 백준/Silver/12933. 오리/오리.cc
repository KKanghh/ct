#include <bits/stdc++.h>
using namespace std;
int ori[4];
int mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'q') ori[0]++;
    if (s[i] == 'u') {
      ori[0]--;
      ori[1]++;
    }
    if (s[i] == 'a') {
      ori[1]--;
      ori[2]++;
    }
    if (s[i] == 'c') {
      ori[2]--;
      ori[3]++;
    }
    if (s[i] == 'k') {
      ori[3]--;
    }

    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      if (ori[j] < 0) {
        cout << -1;
        return 0;
      }
      cnt += ori[j];
    }
    mx = max(mx, cnt);
  }
  
  for (int j = 0; j < 4; j++) {
    if (ori[j] != 0) {
      cout << -1;
      return 0;
    }  
  }
  cout << mx;
}