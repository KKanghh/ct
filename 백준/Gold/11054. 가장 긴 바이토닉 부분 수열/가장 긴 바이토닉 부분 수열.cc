#include <bits/stdc++.h>
using namespace std;

int num[1000], A[1000], B[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> num[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) A[i] = max(A[j] + 1, A[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (num[i] > num[j]) B[i] = max(B[j] + 1, B[i]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) ans = max(ans, A[i] + B[i] + 1);
    cout << ans;
}