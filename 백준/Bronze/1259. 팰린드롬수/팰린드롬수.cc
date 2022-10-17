#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string num;
    cin >> num;
    while (num != "0") {
        int length = num.length();
        bool isValid = true;
        for (int i = 0; i < length / 2; i++) {
            if (num[i] != num[length - 1 - i]) {
                isValid = false;
                break;
            }
        }
        if (isValid) cout << "yes" << '\n';
        else cout << "no" << '\n';
        
        cin >> num;
    }
}