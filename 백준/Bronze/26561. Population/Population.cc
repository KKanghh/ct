#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int p, n;
        cin >> p >> n;
        p += n / 4;
        p -= n / 7;
        
        cout << p << '\n';
    }
}