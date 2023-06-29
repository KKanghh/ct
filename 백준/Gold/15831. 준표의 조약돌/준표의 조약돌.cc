#include <bits/stdc++.h>
using namespace std;
string s;
int mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, w, b;
  cin >> n >> b >> w;

  int b_cnt = 0;
  int w_cnt = 0;
  int en = 0;

  cin >> s;

  for (int st = 0; st < n; st++) {
    while (en < n && b_cnt + (s[en] == 'B') <= b) {
      if (s[en] == 'W') w_cnt++;
      else b_cnt++;
      en++;
    }

    if (w_cnt >= w) {
      mx = max(mx, en - st);
    }

    if (s[st] == 'W') w_cnt--;
    else b_cnt--;
  }
  
  cout << mx;

}