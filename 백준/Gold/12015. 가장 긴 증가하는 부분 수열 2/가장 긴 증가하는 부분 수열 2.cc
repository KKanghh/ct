#include <bits/stdc++.h>
using namespace std;

int num[1000000];
vector<int> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> num[i];

    V.push_back(num[0]);

    for (int i = 1; i < n; i++) {
        if (num[i] > V[V.size() - 1]) V.push_back(num[i]);
        else V[lower_bound(V.begin(), V.end(), num[i]) - V.begin()] = num[i];
    }

    cout << V.size();
}