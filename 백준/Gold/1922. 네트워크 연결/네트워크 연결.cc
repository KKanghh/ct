#include <bits/stdc++.h>
using namespace std;

int p[1001];
vector<tuple<int, int, int>> V;

int find(int a) {
    if (p[a] <= 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (p[a] > p[b]) swap(a, b);

    p[b] = a;
    p[a]--;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({c, a, b});
    }

    sort(V.begin(), V.end());

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        tie(a, b, c) = V[i];

        if (find(b) == find(c)) continue;
        merge(b, c);
        ans += a;
    }
    cout << ans;
}