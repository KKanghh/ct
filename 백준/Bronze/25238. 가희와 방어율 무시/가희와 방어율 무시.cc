#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    cin >> a >> b;
    b = 100 - b;
    double c = a * b / 100;
    if (c >= 100) cout << 0;
    else cout << 1;
}