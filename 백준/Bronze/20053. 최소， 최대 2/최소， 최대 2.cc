#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> V;
        int n;
        cin >> n;
        while (n--) {
            int k;
            cin >> k;
            V.push_back(k);
        }

        int mn = 1e6, mx = -1e6;
        for (int i = 0; i < V.size(); i++) {
            mn = min(V[i], mn);
            mx = max(V[i], mx);
        }
       
        cout << mn << ' ' << mx << '\n';
    }
}