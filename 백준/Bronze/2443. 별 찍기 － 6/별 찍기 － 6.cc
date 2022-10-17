#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    
    cin >> num;
    
    for (int i = num; i > 0; i--) {
        for (int j = 0; j < num - i; j++) cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++) cout << '*';
        cout << '\n';
    }
}