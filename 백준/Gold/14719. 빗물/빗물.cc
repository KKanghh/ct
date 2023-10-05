#include <bits/stdc++.h>
using namespace std;

int D[500];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h;
  int cnt = 0;
  cin >> h >> w;

  for (int i = 0; i < w; i++) cin >> D[i];

  for (int i = 1; i < w - 1; i++) {
    int leftmx = 0, rightmx = 0;
    for (int a = i - 1; a >= 0; a--) {
      leftmx = max(leftmx, D[a]);
    }

    for (int b = i + 1; b < w; b++) {
      rightmx = max(rightmx, D[b]);
    }

    cnt += max(0, min(leftmx, rightmx) - D[i]);
  }

  cout << cnt;
}