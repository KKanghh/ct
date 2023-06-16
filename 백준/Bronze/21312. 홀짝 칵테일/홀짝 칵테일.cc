#include <bits/stdc++.h>
using namespace std;
priority_queue<int> odd, even;
int num[3];
int n = 1;

void dfs(int k) {
  for (int i = k; i < 3; i++) {
    n *= num[i];
    if (n % 2) odd.push(n);
    else even.push(n);
    dfs(i + 1);
    n /= num[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) cin >> num[i];

  dfs(0);

  if (odd.empty()) cout << even.top();
  else cout << odd.top();

}