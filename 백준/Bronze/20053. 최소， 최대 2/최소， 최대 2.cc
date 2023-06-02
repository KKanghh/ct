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
        sort(V.begin(), V.end());
        cout << V[0] << ' ' << V[V.size() - 1] << '\n';
    }
}