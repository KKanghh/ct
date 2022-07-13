#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int H, M, t;
    cin >> H >> M >> t;
    M += t;
    H += M / 60;
    M = M % 60;
    H = H % 24;
    
    cout << H << ' ' << M;
}