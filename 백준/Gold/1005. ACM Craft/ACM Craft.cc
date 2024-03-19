#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int s[1001], ind[1001], f[1001];
queue<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < 1001; i++) adj[i].clear();
        fill(ind, ind + 1001, 0);
        fill(f, f + 1001, 0);

        for (int i = 1; i <= n; i++) cin >> s[i];

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            ind[b]++;
        }

        int w;
        cin >> w;

        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) {
                Q.push({i, s[i]});
            }
        }

        while (!Q.empty()) {
            int a, b;
            tie(a, b) = Q.front();
            Q.pop();
            f[a] = b;

            for (int c: adj[a]) {
                ind[c]--;
                f[c] = max(f[c], f[a] + s[c]);
                if (ind[c] == 0) {
                    Q.push({c, f[c]});
                }
            }
        }

        cout << f[w] << '\n';
    }
}