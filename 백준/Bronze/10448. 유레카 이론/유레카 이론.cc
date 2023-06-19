#include <bits/stdc++.h>
using namespace std;
vector<int> triangle;
bool ans[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 0;
  int k = 1;
  while (n <= 1000) {
    n += k++;
    triangle.push_back(n);
  }

  for (int x = 0; x < triangle.size(); x++) {
    for (int y = x; y < triangle.size(); y++) {
      for (int z = y; z < triangle.size(); z++) {
        int sum = triangle[x] + triangle[y] + triangle[z];
        if (sum > 1000) break;
        ans[sum] = true;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << ans[k] << '\n';
  }
}