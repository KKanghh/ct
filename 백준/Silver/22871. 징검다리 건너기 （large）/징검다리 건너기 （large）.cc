#include <bits/stdc++.h>
using namespace std;
long long D[5001], A[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    fill(D + 1, D + n + 1, 0x3f3f3f3f);
    D[1] = 0;
    for (int i = 1; i <= n; i++) cin >> A[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            D[i] = min({D[i], max(D[j], (i - j) * (1 + abs(A[i] - A[j])))});
        }
    }

    cout << D[n];
}