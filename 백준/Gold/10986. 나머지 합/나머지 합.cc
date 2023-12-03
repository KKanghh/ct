#include <bits/stdc++.h>
using namespace std;
int num[1000001], D[1000001];
int cnt[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m = 0;
    cnt[0] = 1;
    long long ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i + 1];
        D[i + 1] = (D[i] + (num[i + 1] % m)) % m;
        ans += cnt[D[i + 1]];
        cnt[D[i + 1]]++;
    }
    cout << ans;

}