#include <bits/stdc++.h>
using namespace std;

int A[5000];
bool vis[5000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> A[i];
    vis[0] = true;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if ((j - i) * (1 + abs(A[j] - A[i])) <= k) vis[j] = true;
        }
    }

    if (vis[n - 1]) cout << "YES";
    else cout << "NO";
    
}