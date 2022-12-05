#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a1, a2, a3, a4, a5, b1, b2, b3, b4, b5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> b1 >> b2 >> b3 >> b4 >> b5;
    
    cout << 6 * a1 + 3 * a2 + 2 * a3 + a4 + 2 * a5 << '\n' << 6 * b1 + 3 * b2 + 2 * b3 + b4 + 2 * b5;
}