#include <bits/stdc++.h>
using namespace std;
int V[1000000];
deque<int> dq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> V[n - i];
    }

    for (int i = 1; i <= n; i++) {
        int m = V[i - 1];

        if (m == 1) {
            dq.push_front(i);
        }
        if (m == 2) {
            dq.push_front(i);
            swap(dq[0], dq[1]);
        }
        if (m == 3) {
            dq.push_back(i);
        }
    }

    for (int e: dq) cout << e << ' ';

}