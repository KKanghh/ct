#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    stack<int> S;
    
    for (int i = 0; i < num; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int add;
            cin >> add;
            S.push(add);
        }
        else if (input == "top") {
            if (S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
        else if (input == "size") {
            cout << S.size() << '\n';
        }
        else if (input == "empty") {
            cout << S.empty() << '\n';
        }
        else {
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
    }
}