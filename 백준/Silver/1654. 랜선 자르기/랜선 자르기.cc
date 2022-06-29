#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

priority_queue<pair<double, int>> Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N;
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        double temp;
        cin >> temp;
        Q.push({ temp, 1 });
    }


    while (N--) {
        double a;
        int b;
        a = Q.top().X;
        b = Q.top().Y;
        if (N == 0) cout << (int)(Q.top().X);
        Q.pop();
        Q.push({ a * b / (b + 1), b + 1 });
    }
}