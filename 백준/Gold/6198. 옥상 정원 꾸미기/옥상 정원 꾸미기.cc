#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    int num;
    cin >> num;
    long long ans = 0;
    while (num--) {
        int temp;
        cin >> temp;
        
        while (!S.empty() && S.top() <= temp) S.pop();
        ans += S.size();
        S.push(temp);
    }
    
    cout << ans;
}