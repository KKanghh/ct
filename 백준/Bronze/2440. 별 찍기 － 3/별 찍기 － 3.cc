#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    while (num > 0) {
        for (int i = 0; i < num; i++) {
            cout << '*';
        }
        cout << '\n';
        num--;
    }
}