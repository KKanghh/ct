#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;

    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
            res %= 10;
        }
        if (res == 0) res = 10;
        cout << res << '\n';
    }
}