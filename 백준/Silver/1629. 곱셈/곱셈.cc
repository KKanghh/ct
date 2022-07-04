#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b, long long c) {
    if (b == 1) return a % c;
    long long t = mul(a, b / 2, c);
    t = t * t % c;
    if (b % 2 == 0) {
        return t;
    }
    else {
        return (t * a) % c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;

    cout << mul(a, b, c);
}