#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        
        if (temp) S.push(temp);
        else {
            S.pop();
        }
    }
    
    int result = 0;
    while (!S.empty()) {
        result += S.top();
        S.pop();
    }
    
    cout << result;
}