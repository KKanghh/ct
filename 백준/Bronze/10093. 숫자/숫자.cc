#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long a[2];
    
    cin >> a[0] >> a[1];
    
    sort(a, a + 2);
    if (a[0] == a[1]) cout << 0 << '\n';
    else cout << a[1] - a[0] - 1 << '\n';
    for (long long i = a[0] + 1; i < a[1]; i++) cout << i << ' ';
}