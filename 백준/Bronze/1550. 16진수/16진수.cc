#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int k = s.length();
    int m = 1;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (s[k - 1 - i] >= '0' && s[k - 1 - i] <= '9') {
            ans += m * (s[k - 1 - i] - '0');
        }
        else ans += m * (s[k - 1 - i] - 'A' + 10);
        
        m *= 16;
    }
    
    cout << ans;
}