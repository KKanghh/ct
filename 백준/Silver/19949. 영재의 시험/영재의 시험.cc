#include <bits/stdc++.h>
using namespace std;
int ans[10];
vector<int> V;
int cnt;

void dfs() {
  if (V.size() == 10) {
    int score = 0;
    for (int i = 0; i < 10; i++) score += V[i] == ans[i];
    if (score >= 5) cnt++;
    return;
  }
  for (int i = 1; i <= 5; i++) {
    if (V.size() >= 2 && V[V.size() - 2] == i && V[V.size() - 1] == i) continue;
    V.push_back(i);
    dfs();
    V.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 10; i++) cin >> ans[i];

  dfs();

  cout << cnt;

}