#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int total;
    cin >> total;
    
    int n;
    cin >> n;
    int m = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        m += a * b;
    }
    
    if (total == m) cout << "Yes";
    else cout << "No";
}