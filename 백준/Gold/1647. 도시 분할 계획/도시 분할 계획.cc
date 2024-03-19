#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> V;
int p[100001];

int find(int a) {
    if (p[a] <= 0) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (p[a] > p[b]) swap(a, b);
    p[a]--;
    p[b] = a;
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

    int cnt = 0, ans = 0;
    
    for (int i = 0; i < m; i++) {
        if (cnt == n - 2) break;
        int a, b, c;
        tie(c, a, b) = V[i];

        if (find(a) == find(b)) continue;

        cnt++;
        merge(a, b);
        ans += c;
    }

    cout << ans;
}