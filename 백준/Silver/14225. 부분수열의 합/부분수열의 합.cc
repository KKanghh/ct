#include <bits/stdc++.h>
using namespace std;
int D[20];
int n, sum;
set<int> S;

void dfs(int k) {
    if (k == n) {
        S.insert(sum);
        return;
    }

    sum += D[k];
    dfs(k + 1);
    sum -= D[k];

    dfs(k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> D[i];
    dfs(0);

    int cnt = 1;

    while (S.count(cnt)) cnt++;

    cout << cnt;

}